from flask import Flask,flash, redirect,abort,Response,jsonify
from flask import request,render_template, url_for
import paho.mqtt.client as mqtt
import json
import time
c1=mqtt.Client()
error =" "
list = ["up","down","left","right","a","b","c","d","e","f","g","h"]
def on_message(client, userdata, message):
	global list
	x = str(message.payload.decode("utf-8"))
	x = x.strip()
	global error
	if x not in list:
		error = x
	print(error)



app = Flask(__name__)

@app.route('/update_error', methods=['POST'])
def update_error():
	global error
	d = request.form

	return Response(error, mimetype="text/plain")

@app.route('/')
def hello_world():
    c1.connect("broker.mqttdashboard.com") #connect to broker
    c1.on_message=on_message
    c1.loop_start()
    c1.subscribe("winchat")
    return render_template('index.html')

@app.route('/buttonclick', methods=['POST'])
def buttonclick():
    data = request.form
    var = data["data"]
    print(var)
    c1.publish("winchat"," "+var)
    return Response("hi", mimetype="text/plain")


@app.route('/formsubmit', methods=['POST'])
def formsubmit():
	projectpath = request.form['projectFilepath']
	print(projectpath)
	c1.publish("winchat"," "+projectpath)
	return render_template('index.html')


if __name__ == '__main__':
    app.run()
