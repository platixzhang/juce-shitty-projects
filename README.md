# juce-shitty-projects
All the craps that I made for practicing using JUCE.

This is not only a readme file but a shitty log as well.
Which will be written in Chinese since my English is desperately bad.

2020.10.21
感谢许彧玮大佬的指导，让我纠结了半个月的问题被解决了。一想到关于这方面我在StackOverflow和Git上找到的结果并不多，就分享一下（也有可能是因为我他妈的太菜了）。这个是在Processor里如何把信息发给Editor。解决办法是写个Message的派生类，做中间件。其实就是把MidiMessage（这是个指针指向进入的midimessage）通过这个中间件传过去。美滋滋，再次谢谢许佬。
