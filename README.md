UDPInterceptProxy
=================

UDPInterceptProxy is a UDP proxy which allows incoming packets to be processed and conditionally redirected according to a packet's contents.

Use Case
=================

A client is communicating with a target server through a UDP proxy, but only some packets should be redirected to the target.

Packets that should be redirected to the target are passed through the proxy and onto the destination using a unique socket for a specific client.

Packets that should not be redirected to the target are processed, and the proxy can respond. These packets never reach the destination server.


