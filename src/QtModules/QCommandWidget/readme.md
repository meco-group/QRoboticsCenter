QCommandWidget
==============

This widget handles all incoming data which are supplied from outside the program and should be redirected to a QDataNode within the program. Implemented data streams are for now:

* tab-separated CSV files
* incoming serial data on a UDP port
* gamepad device

Things you need to know:
The data is pushed by the program to the connected QDataNode. This means that the SUPPLIER of data is responsible for the amount of data generated.

* In case of a CSV file, lines are read at the specified frequency. As a user, you should make sure that the CSV file indeed contains the right samples for the specific frequency.
* In case of a UDP port, data is read at the specified frequency. The supplier of the UDP messages is responsible for messages to arrive in time. If no message has arrived, i.e. the number of bytes is zero, no message will be pushed to the receiving QDataNodes
