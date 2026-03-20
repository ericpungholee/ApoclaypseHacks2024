# ApocaLift

**Uber for drones. Request, deploy, and remotely control drones through a web app.**

---

## Demo
[![ApocaLift demo — click to watch on YouTube](https://img.youtube.com/vi/tAjU9ZEyOP8/hqdefault.jpg)](https://youtu.be/tAjU9ZEyOP8)
Click on the video
- Live drone control via browser
- Real-time video and control interface
- Command transmission to physical drone hardware
---

## Problem

In emergency, remote, or high-risk environments, getting physical access is slow, expensive, or dangerous.

Whether it is disaster zones, hard-to-reach infrastructure, or time-sensitive delivery, there is no simple way for an average user to instantly deploy and control a drone on demand.

Existing drone systems:

- require manual setup and expertise
- are not remotely accessible
- lack real-time, user-friendly control interfaces

---

## Solution

ApocaLift lets users:

- request a drone through a web app
- instantly connect to a live drone feed
- remotely control the drone in real time

We built a full-stack system that turns drones into on-demand, internet-controlled services, similar to how Uber turned cars into on-demand transportation.

---

## Product

### Core Features

- real-time drone control from the browser
- live video streaming from drone to user
- low-latency command transmission
- simple request to connect to control flow

---

## How It Works

1. User opens the web app
2. Requests a drone
3. Connects to a live drone session
4. Sends control inputs from the browser
5. Commands are transmitted through Python to ESP32 hardware
6. The vehicle responds in real time with live video feedback

---

## Tech Stack

- Backend: Flask, Flask-Login, Flask-WTF, SQLAlchemy, Bcrypt
- Frontend: HTML, CSS, JavaScript
- Hardware Control: Python serial communication, ESP32, ESP-NOW
- Video Streaming: Raspberry Pi camera feed served to the web interface
- Data Layer: SQLite for the prototype app

---

## Why Now

- cheap and accessible drone hardware
- ubiquitous internet connectivity
- growing demand for remote operations
- increasing need for automation in physical environments

This enables drones to move from manual tools to on-demand infrastructure.

---

## Market Insight

This is part of a broader shift:

> Turning physical systems into software-controlled services

Similar to:

- Uber for cars
- DoorDash for delivery
- ApocaLift for drones

---

## Traction

- built a working prototype in a hackathon environment
- placed Top 10 at Apocalypse Hacks
- received strong feedback from Shopify engineers on execution and technical depth

---

## Vision

ApocaLift becomes the infrastructure layer for:

- emergency response
- remote inspection
- on-demand aerial services
- autonomous logistics

Long term:

> A network of remotely accessible drones deployed across cities
