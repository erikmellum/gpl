CSCI 515
Program 2

Steps to getting this to work
1) copy all these files to your machine (download p2.tar.gz and un-tar it)
2) edit the Makefile so it is configured for your machine (Linux or OSX)
3) type:  $ make make
4) type:  $ make

NOTE: you will get lots of errors for library files on step (3)
  if step (3) failed to find makedepend, install makedepend
  if step (4) failed, Check the software installation page:

	~tyson/515/docs/software_installation.html

You can experiment with the parser in two ways:

1) put one or more declarations in a filename, and run the parser

	$ parser filename

2) run the parser and type in the declaration(s)

	$ parser <return>
	....
	foo[] = {1,2,3,4};
	bar[] = {42, 86};
	^D

Note:  in the UNIX/Linux world ^D (control-D) signals end of file (EOF).
