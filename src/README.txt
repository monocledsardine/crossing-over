Alright, are you ready for this? This may be a little tricky to get done the first time,
but when it's over it will be much, much nicer for you. Make sure to follow all the steps
carefully and in order.

						----- Level 1. BUILDING SFML ------

	**	We are using the SFML source code, which we may eventually edit into	**
	**	our own customized framework. This means that to get our project 		**
	**	running, we will first have to build SFML.								**
		
IMPORTANT: Replace *DEATH* with the full name of the directory where the folder 
crossing-over (the Github-made directory) is
NOT IMPORTANT: "/" and "\" in filenames are interchangeable, thanks to MinGW compilers 

1. Open the CMake GUI (Graphical User Interface).

2. Click "Browse Source" and set the value to: *DEATH*/src/SFML

3. Set the value to "Browse Build" to: *DEATH*/sfml-build (just type it in)

4. Push "Configure". Yes, you want to make that directory. Make sure the Generator is set 
to "MinGW Makefiles" and push "Finish". You will always use MinGW, so do this in the 
future.

5. A bunch of red options will pop up. The default values should be fine, except for one.
Change "CMAKE_INSTALL_PREFIX" to: *DEATH*/build/SFML . The variable CMAKE_INSTALL_PREFIX
is just the install directory for your project, which in this case is SFML.

6. Press Configure again, and then press Generate.

	** 	An ignorable note: All these separate directories are not strictly 	**	
	** 	necessary, but it helps keep different parts of the build process 	**
	** 	away from each other so you can delete and change them. In this 	**
	**	case, "src/SFML" is where all the code is - the stuff that you are 	**
	** 	allowed to edit. "sfml-build" is for the instructions that CMake 	**
	**	creates to get the project to build. Finally, "build/SFML" is the 	**
	** 	compiled output. Clicking Configure and Generate has created the	**
	** 	build instruction files (sfml-build/), but to actually build it, you**
	**	have to use MinGW or another compiler.								**

7. Open cmd. Navigate to the *DEATH*/sfml-build folder (this can be done with the "cd" 
command i.e. "cd C:/MY DEATH LOCATION/crossing-over/sfml-build". Hint: you can paste with 
right click).

8. Type in "mingw32-make install", and look at all the pretty colors for a little while.

SFML is installed! Good job! You did it! Have a cupcake and a potty break.





					----- Level 2. BUILDING THE DEATH GAME -----
		
	** 	We've conveniently put our installation of SFML into the "build"	**
	** 	folder. I say this is convenient because we are going to stick the	**
	** 	CMake build files (just the stuff that gets it to build, not the	**
	**	real deal) for our game in the same folder. This makes it easy to 	**
	** 	install the whole package at the same time.							**

1. Set "Browse Source" in the CMake GUI to *DEATH*/src

2. Set "Browse Build" to *DEATH*/build

3. Click "Configure"

4. You should have a couple red boxes. Make sure "SFML_DIR" is the same as 
*DEATH*/build/SFML. Then change "CMAKE_INSTALL_PREFIX" to *DEATH*/bin (bin for binary. 
It doesn't really have to be here - you could put it anywhere you want)

5. Hit Configure, then Generate.

6. Open cmd and navigate to the build directory, *DEATH*/build. Type in "mingw32-make install"

You should find a working copy of Death.exe in the "bin" directory. :) 

Now that you've done it for the first time, you really don't need to do much work anymore. 
Just change the code in "src", then open cmd to "build" and type "mingw32-make", and the .exe 
in "bin" will be updated. From now on, the only time you need to open CMake is if we add new 
code files or some other structural changes. Also note that everything in the "images" folder 
will be transferred over regardless. 

If you want to start messing with the code, open TextureStore.cpp in a text editor. This file
contains all the references to external images. If you want to change things but you don't
want them to ever be included on github, you can change them in the build folder! I'll give 
you more instructions about what you can do later on.

Sorry about how confusing this all is. Now perhaps you have a vague idea of why it was taking
so long, eh?	

