import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

dic = {"rafael": {"nome": "Rafael Antoniassi Vicechio", "cpf": "51256824895", "cargo": "desenvolvedor", "salario": "10.000"}}
dicname = {}

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():

    # Declare a variable that will increment
    increment = 0


    # Select all stocks present at the database where id is equal to the current loged in user
    stocks = db.execute(
        "SELECT * FROM stocks WHERE id = ?", session["user_id"])

    # Save the sum of all the brought stocks on a variable
    storage = db.execute(
        "SELECT sum(price_total) FROM stocks WHERE id = ?", session["user_id"])
    for item in storage:
        sum = item["sum(price_total)"]
        if sum:
            increment += 1

    return render_template("index.html", dic=dic)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        dic[request.form.get("nome")] = {"nome": request.form.get("nome"), "cpf":  request.form.get("cpf"), "cargo":  request.form.get("cargo"), "salario":  request.form.get("salario")}
        return redirect("/")
    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        if (request.form.get("username") == "rafa"):
                return apology("Nenhum usuario encontrado")
        return render_template("index.html", dic=dic)


        # Redirect user to home page

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        # Check if given stock symbol exists in API database
        if not lookup(request.form.get("symbol")):
            return apology("Nothing has been found")

        # Create a variable to receive the variable that the lookup function returns
        stocks = lookup(request.form.get("symbol"))

        return render_template("quoted.html", stocks=stocks)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password and confirmation were submitted
        elif not request.form.get("password") and not request.form.get("confirmation"):
            return apology("must provide password and confirmation", 400)

        # Pass user input to variables
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        
        dicname[username] = {"name": username, "password": password}

        # Redirect user to login form
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "POST":
        dic.pop(request.form.get("nome"))
        return redirect("/")
    else:
        return render_template("sell.html")
