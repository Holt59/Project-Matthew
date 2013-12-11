function blkStruct = slblocks
blkStruct.Name = 'AR.Drone v2 Toolbox';
blkStruct.OpenFcn = 'ardrone_lib';
blkStruct.MaskDisplay = '';
Browser(1).OpenFcn = 'ardrone_lib';
Browser(1).Name = 'ardrone_lib';
blkStruct.Browser = Browser;
