# How the Internet Works

# Introduction

The Internet is one of the greatest inventions in modern technology. Every time you open Google, watch a YouTube video, send a WhatsApp message, or browse a website, thousands of computers communicate with each other within milliseconds.

To understand web development, networking, and backend development, it is important to understand **how the Internet works**.

---

# What is the Internet?

The Internet is a **global network of interconnected computers** that communicate using standard networking protocols.

Every device connected to the Internet can send and receive information.

Examples of devices connected to the Internet:

* Computers
* Smartphones
* Tablets
* Servers
* Smart TVs
* IoT Devices

Think of the Internet as a huge road system where information travels from one computer to another.

---

# Why Was the Internet Created?

The Internet was created to allow computers to:

* Share information
* Communicate quickly
* Exchange files
* Access remote resources
* Connect people across the world

Today it powers:

* Websites
* Mobile Apps
* APIs
* Cloud Computing
* Online Gaming
* Video Streaming

---

# Internet vs World Wide Web

Many people think they are the same, but they are different.

| Internet             | World Wide Web         |
| -------------------- | ---------------------- |
| Network of computers | Collection of websites |
| Infrastructure       | Runs on the Internet   |
| Uses TCP/IP          | Uses HTTP/HTTPS        |

Example:

```text
Internet = Roads

World Wide Web = Cars travelling on those roads
```

---

# Internet Architecture

```text
                     INTERNET

        +----------------------------+
        |        Web Server          |
        +----------------------------+
                   ▲
                   │
             HTTP / HTTPS
                   │
        +----------------------------+
        |        Internet            |
        | (Routers + Fiber + DNS)    |
        +----------------------------+
                   ▲
                   │
            ISP (Internet Provider)
                   ▲
                   │
        +----------------------------+
        |      WiFi Router           |
        +----------------------------+
                   ▲
                   │
        +----------------------------+
        | Browser (Chrome/Firefox)   |
        +----------------------------+
```

---

# Main Components

The Internet consists of:

* Client
* Browser
* ISP
* DNS Server
* Routers
* Internet Backbone
* Web Server
* Database

---

# Client

The client is the device requesting information.

Examples:

* Laptop
* Mobile
* Desktop
* Tablet

---

# Browser

A browser is software that requests webpages.

Examples:

* Chrome
* Firefox
* Edge
* Safari

The browser sends HTTP requests and displays responses.

---

# ISP (Internet Service Provider)

The ISP connects your home or office to the Internet.

Examples:

* PTCL
* StormFiber
* Nayatel
* Comcast
* AT&T

Without an ISP your device cannot access the Internet.

---

# URL (Uniform Resource Locator)

A URL tells the browser where a resource is located.

Example:

```text
https://www.example.com/products?id=10
```

Breakdown:

```text
https://   -> Protocol
www.example.com -> Domain
/products -> Path
?id=10 -> Query Parameters
```

---

# DNS (Domain Name System)

Humans remember names.

Computers understand IP addresses.

DNS converts:

```text
google.com
```

into

```text
142.250.xxx.xxx
```

Think of DNS as the Internet's phone book.

---

# IP Address

Every device connected to the Internet has an IP address.

Example:

```text
192.168.1.10
```

or

```text
142.250.183.46
```

An IP address uniquely identifies a device on a network.

---

# Routers

Routers connect different networks together.

Their job is to determine the best path for data packets.

Example:

```text
Laptop

↓

Home Router

↓

ISP Router

↓

Internet Backbone

↓

Google Server
```

---

# Switches

Switches connect devices inside the same local network.

Example:

```text
Office

Computer A

↓

Switch

↓

Computer B
```

---

# Packets

Data does not travel as one large file.

It is divided into small pieces called **packets**.

Example:

Large File

```text
100 MB
```

becomes

```text
Packet 1

Packet 2

Packet 3

Packet 4

...

Packet N
```

Each packet travels independently.

The destination reassembles them.

---

# TCP (Transmission Control Protocol)

TCP provides reliable communication.

Features:

* Guaranteed delivery
* Ordered packets
* Error checking
* Retransmission

Used by:

* HTTP
* HTTPS
* Email
* FTP

---

# UDP (User Datagram Protocol)

UDP is faster but less reliable.

Features:

* No guarantee
* No retransmission
* Lower latency

Used by:

* Video calls
* Live Streaming
* Gaming
* Voice Chat

---

# HTTP

HTTP stands for HyperText Transfer Protocol.

It defines how browsers communicate with web servers.

Example Request:

```http
GET / HTTP/1.1
Host: example.com
```

Server Response:

```http
HTTP/1.1 200 OK
Content-Type: text/html
```

---

# HTTPS

HTTPS is the secure version of HTTP.

It encrypts communication using SSL/TLS.

Benefits:

* Secure
* Private
* Encrypted
* Prevents attackers from reading data

---

# SSL/TLS

SSL/TLS encrypts all communication.

Without HTTPS:

```text
Browser

↓

Password

↓

Internet

↓

Anyone can read it
```

With HTTPS:

```text
Browser

↓

Encrypted Password

↓

Internet

↓

Only the Server can decrypt it
```

---

# Web Server

The server receives requests and returns responses.

Examples:

* Node.js
* Nginx
* Apache
* Express
* IIS

The server may:

* Read a database
* Perform calculations
* Authenticate users
* Return HTML or JSON

---

# Database

Many applications store data in databases.

Examples:

* MongoDB
* PostgreSQL
* MySQL
* Redis

Example:

Browser requests

```text
/users/5
```

Server queries database

Returns

```json
{
    "id":5,
    "name":"John"
}
```

---

# CDN (Content Delivery Network)

A CDN stores copies of files at multiple locations around the world.

Instead of downloading from the original server:

```text
Pakistan

↓

USA Server
```

You may download from

```text
Pakistan

↓

Pakistan CDN Server
```

Benefits:

* Faster loading
* Lower latency
* Better performance

Examples:

* Cloudflare
* Akamai
* AWS CloudFront

---

# Complete Request Lifecycle

Suppose the user types:

```text
https://www.google.com
```

### Step 1

Browser checks cache.

If found:

Return cached page.

Otherwise continue.

---

### Step 2

Browser asks DNS:

```text
Where is google.com?
```

DNS returns:

```text
142.xxx.xxx.xxx
```

---

### Step 3

Browser establishes a TCP connection.

If HTTPS:

SSL/TLS handshake occurs.

---

### Step 4

Browser sends an HTTP request.

```http
GET /
```

---

### Step 5

Request travels through:

```text
Laptop

↓

WiFi Router

↓

ISP

↓

Internet Routers

↓

Google Server
```

---

### Step 6

Server processes the request.

Possible operations:

* Authenticate
* Query database
* Generate HTML
* Generate JSON

---

### Step 7

Server sends an HTTP response.

```http
HTTP/1.1 200 OK
```

---

### Step 8

Response travels back through the Internet.

---

### Step 9

Browser receives the response.

---

### Step 10

Browser parses:

* HTML
* CSS
* JavaScript

Downloads additional resources.

---

### Step 11

Browser renders the webpage.

The user finally sees the website.

---

# Complete Internet Flow

```text
User

↓

Browser

↓

DNS Lookup

↓

IP Address Found

↓

TCP Connection

↓

HTTPS Handshake

↓

HTTP Request

↓

ISP

↓

Routers

↓

Internet Backbone

↓

Web Server

↓

Database (if required)

↓

HTTP Response

↓

Browser

↓

HTML Parsing

↓

CSS Parsing

↓

JavaScript Execution

↓

Webpage Displayed
```

---

# Summary

* The Internet is a global network of interconnected computers.
* Browsers communicate with servers using HTTP or HTTPS.
* DNS converts domain names into IP addresses.
* Routers forward packets across networks.
* Data travels as packets.
* TCP provides reliable communication, while UDP prioritizes speed.
* HTTPS secures communication using SSL/TLS encryption.
* Web servers process requests and return responses.
* Browsers parse and render HTML, CSS, and JavaScript to display webpages.
* Every website visit involves DNS lookup, TCP connection, HTTP request, server processing, and browser rendering, all happening within milliseconds.
