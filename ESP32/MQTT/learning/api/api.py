from flask import Flask, jsonify, request

app = Flask(__name__)

@app.route('/connect', methods=['GET'])
def connect():
    print("Received connection request from ESP32")
    return jsonify(message="ESP32 connected successfully"), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
