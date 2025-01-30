import json
from flask import Flask, request
from waitress import serve
from ping import find
import keys

app = Flask(__name__)


@app.route("/")
def protected_function():
    # Get the API key from the request headers
    # find()
    api_key = request.headers.get("X-API-Key")
    print(api_key)

    # Check if the API key is valid
    if api_key == keys.API_KEY:
        # Run your Python function
        print("looking")
        try:
            return (
                json.dumps({"success": True}),
                200,
                {"ContentType": "application/json"},
            )
        finally:
            find()

        # Return a 200 OK response
    else:
        # Return an error message if the API key is invalid
        print("invalid")

        return "Unauthorized", 401


if __name__ == "__main__":
    serve(app, host="0.0.0.0", port=1200)
