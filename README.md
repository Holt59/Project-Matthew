Project-Matthew
===============
###Code Generation Toolbox for Parrot AR.Drone

__Official Website__ : [https://sites.google.com/site/projetsecinsa/projets-2013-2014/project-matthew](https://sites.google.com/site/projetsecinsa/projets-2013-2014/project-matthew)

We are willing to make a platform that allows nearly everybody to make easily their own AR.Drone applications. We want this tool to be graphical, and integrated to Matlab/Simulink, as this is a very well-known tool.

###What is Bib'Rone?

Bib'Rone is our own drivers library for AR.Drone 2.0. We based our work on the paparazzi project (see https://github.com/paparazzi/paparazzi) but modified a lot of code and add some functionalities.

###How to install the target in MATLAB?

To install the target, just add the following directories in your MATLAB path by running the command <code>addpath(genpath('/path_to_the_folder/target/ardrone')):
<pre><code>
targets/ardrone
targets/ardrone/ardrone
targets/ardrone/blocks
targets/ardrone/doc</pre></code>

To definitively save the target in MATLAB path:
<pre><code>
> addpath(genpath('/path_to_the_folder/target/ardrone'))
> savepath 
</code></pre>

