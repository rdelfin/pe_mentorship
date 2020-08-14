#!/bin/sh
export FLASK_APP=server.py
setsid flask run -p 8080 --host=0.0.0.0 > /dev/null 2> /dev/null &
