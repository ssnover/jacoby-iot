# Jacoby Protocol
This document describes the different layers of the Jacoby serial protocol.

The protocol consists of three layers: the Data Link Layer, Packet Layer, and Application Layer.

## Data Link Layer
This layer is the outermost layer of Jacoby and contains only the header signifying a new message, and a footer containing a 1 byte CRC and the trailing three bytes signifying the end of the message.

The Data Link Layer's header trail consists of three bytes: 0xAA - 0xAA - 0xAA.
The Data Link Layer's payload consists of a variable number of bytes between 1 and 32 bytes.
The Data Link Layer's footer consists of five bytes, a 1-byte checksum and three bytes: 0xCA - 0xCA - 0xCA.

### Calculating the Checksum
The checksum is calculated with CRC-7 with a polynomial of x^7 + x^5 + x^4 + x^2 + x + 1.
I chose that based on this website: https://betterembsw.blogspot.com/2010/05/whats-best-crc-polynomial-to-use.html

## Packet Layer
The Packet Layer is pretty simple, consisting of just one byte of header and a payload of up to 31 bytes.

The header byte is a bitfield where:
* [7 downto 3]: length of the payload in bytes.
* [2 downto 1]: message type.
  * 00: Command message.
  * 01: Ack message.
  * 10: Heartbeat message.
  * 11: Error message.
* [0 downto 0]: ack requested.

## Application Layer
The Application Layer is the ultimate payload and the innermost layer of the Jacoby protocol.

It typically consists of a 1-byte command and a predefined payload of data for that command. A command is part of a dictionary. A dictionary is simply a list of commands, their 1-byte code, and the associated fields of the payload.

### Dictionaries
All dictionaries support two commands `REQUEST_DICTIONARY_METADATA` with code 0xFF and `DICTIONARY_METADATA_RESPONSE` with code 0xFE.

`REQUEST_DICTIONARY_METADATA` has no data.
`DICTIONARY_METADATA_RESPONSE` has a byte containing a code for the type of dictionary followed by a byte each for the major and minor versions.

A master nucleus on the Jacoby line can use the request command to check which commands are available on the slave coprocessor.