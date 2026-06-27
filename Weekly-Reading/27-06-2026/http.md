# Overview of HTTP (HyperText Transfer Protocol)

# Introduction

HTTP (HyperText Transfer Protocol) is the foundation of communication on the World Wide Web. Every time you visit a website, use a mobile application, or call an API, HTTP is responsible for transferring data between your device and the server.

HTTP defines a set of rules that clients and servers follow while exchanging information.

---

# What is HTTP?

HTTP stands for **HyperText Transfer Protocol**.

* HyperText refers to text containing links.
* Transfer means exchanging data.
* Protocol means a set of communication rules.

HTTP allows a browser (client) to request resources from a web server and receive responses.

Example:

```
Browser → Request → Server
Browser ← Response ← Server
```

---

# Why HTTP is Needed

Without HTTP:

* Browsers would not know how to request webpages.
* Servers would not know how to respond.
* APIs could not exchange JSON data.
* Web applications would not function.

HTTP provides a standardized way of communication.

---

# How HTTP Works

HTTP follows the Request-Response model.

## Step 1

User enters:

```
https://example.com
```

## Step 2

Browser creates an HTTP request.

```
GET / HTTP/1.1
Host: example.com
```

## Step 3

The request is sent to the server.

## Step 4

Server processes the request.

## Step 5

Server sends an HTTP response.

```
HTTP/1.1 200 OK
Content-Type: text/html

<html>
...
</html>
```

## Step 6

Browser renders the webpage.

---

# Client-Server Architecture

```
+-----------+              HTTP Request             +-----------+
|  Browser  | -----------------------------------> |  Server   |
| (Client)  |                                      |           |
|           | <----------------------------------- |           |
+-----------+             HTTP Response            +-----------+
```

Client initiates communication.

Server processes requests and returns responses.

---

# HTTP Request

An HTTP request contains:

* Request Line
* Headers
* Body (optional)

Example:

```
GET /users HTTP/1.1
Host: api.example.com
User-Agent: Chrome
Accept: application/json
```

---

## Components

### Request Method

Examples:

* GET
* POST
* PUT
* PATCH
* DELETE

### URL

```
/users
```

### Headers

Extra information.

Example:

```
Authorization: Bearer token
Content-Type: application/json
```

### Body

Contains data sent to the server.

Example:

```json
{
  "name": "John",
  "age": 25
}
```

---

# HTTP Response

A response contains:

* Status Line
* Headers
* Body

Example

```
HTTP/1.1 200 OK
Content-Type: application/json

{
    "message": "Success"
}
```

---

# HTTP Methods

## GET

Retrieve data.

Example:

```
GET /users
```

---

## POST

Create a resource.

Example:

```
POST /users
```

---

## PUT

Replace an existing resource.

```
PUT /users/5
```

---

## PATCH

Update part of a resource.

```
PATCH /users/5
```

---

## DELETE

Delete a resource.

```
DELETE /users/5
```

---

## HEAD

Returns headers only.

---

## OPTIONS

Returns supported HTTP methods.

---

# HTTP Status Codes

## 1xx

Informational.

Example:

```
100 Continue
```

---

## 2xx

Success.

```
200 OK
201 Created
204 No Content
```

---

## 3xx

Redirection.

```
301 Moved Permanently
302 Found
304 Not Modified
```

---

## 4xx

Client Errors.

```
400 Bad Request
401 Unauthorized
403 Forbidden
404 Not Found
405 Method Not Allowed
409 Conflict
429 Too Many Requests
```

---

## 5xx

Server Errors.

```
500 Internal Server Error
502 Bad Gateway
503 Service Unavailable
504 Gateway Timeout
```

---

# HTTP Headers

Headers provide metadata.

Example:

```
Content-Type
Authorization
Host
Accept
Cookie
Cache-Control
User-Agent
Origin
Referer
```

---

# URL Structure

Example

```
https://www.example.com:443/products/laptops?id=5&page=2#reviews
```

Components:

```
Protocol   : https
Domain     : www.example.com
Port       : 443
Path       : /products/laptops
Query      : id=5&page=2
Fragment   : reviews
```

---

# HTTP vs HTTPS

| HTTP          | HTTPS          |
| ------------- | -------------- |
| Not Secure    | Secure         |
| No Encryption | Encrypted      |
| Port 80       | Port 443       |
| Data Visible  | Data Encrypted |
| Vulnerable    | Safe           |

HTTPS uses SSL/TLS encryption.

---

# Stateless Nature of HTTP

HTTP is stateless.

Meaning:

Each request is independent.

Example:

```
Request 1
↓

Server responds

↓

Request 2

Server does not automatically remember Request 1.
```

---

# Cookies and Sessions

Since HTTP is stateless:

Cookies store information on the client.

Sessions store information on the server.

Example:

```
Login

↓

Server creates Session

↓

Browser stores Cookie

↓

Future requests send Cookie

↓

Server identifies user
```

---

# HTTP Versions

## HTTP/1.0

* One request per connection.

---

## HTTP/1.1

* Persistent connections
* Better caching
* Most widely used

---

## HTTP/2

* Multiplexing
* Header compression
* Faster

---

## HTTP/3

* Uses QUIC instead of TCP
* Lower latency
* Better performance

---

# Caching

Caching reduces server load.

Headers:

```
Cache-Control
Expires
ETag
Last-Modified
```

Benefits:

* Faster loading
* Less bandwidth
* Better performance

---

# Content Types (MIME Types)

Examples:

```
application/json
text/html
text/plain
image/png
image/jpeg
application/pdf
application/xml
multipart/form-data
```

---

# Authentication

Common authentication methods:

## Basic Authentication

Username and password.

---

## Bearer Token

JWT Token.

```
Authorization: Bearer token
```

---

## API Key

```
x-api-key: abc123
```

---

## OAuth

Used by:

* Google
* Facebook
* GitHub

---

# Advantages

* Simple
* Lightweight
* Platform independent
* Widely supported
* Easy to debug
* REST APIs use HTTP

---

# Limitations

* Stateless
* Plain HTTP is insecure
* Additional mechanisms needed for authentication
* Can become slow without caching

---

# Best Practices

* Always use HTTPS.
* Use correct HTTP methods.
* Return proper status codes.
* Validate user input.
* Use authentication.
* Enable caching where appropriate.
* Compress responses.
* Avoid sending unnecessary data.

---

# Real-World Example

Suppose a user logs into a website.

## Request

```
POST /login HTTP/1.1

{
    "email":"john@example.com",
    "password":"123456"
}
```

Server verifies credentials.

## Response

```
HTTP/1.1 200 OK

{
    "token":"abc123xyz"
}
```

Browser stores the token.

Later:

```
GET /profile

Authorization: Bearer abc123xyz
```

Server verifies the token and returns user data.

---

# Summary

* HTTP is the communication protocol of the web.
* It follows a request-response model.
* Clients send requests.
* Servers send responses.
* HTTP is stateless.
* HTTPS is the secure version of HTTP.
* HTTP methods define actions like GET, POST, PUT, PATCH, and DELETE.
* Status codes indicate the result of a request.
* Headers carry metadata.
* Cookies and sessions help maintain user state.
* Modern APIs rely heavily on HTTP and HTTPS for communication.
