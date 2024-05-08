# Cplusplus-Queue
Synchronizing multiple threads of execution via a message queue
Formulation of the problem
There are two devices A and B. Each of them has an access library with a read function, which allows you to read data from the device. Functions are synchronous and blocking. The reading time from device A is 1 second, from device B is 5 seconds (i.e., the readA and readB functions will return control after 1 and 5 seconds, respectively). It is necessary to read data from both devices in parallel and perform data processing, i.e. The situation is unacceptable when we are waiting for device B without processing data from device A. For work, we have a standard PC with a 4-core processor.
