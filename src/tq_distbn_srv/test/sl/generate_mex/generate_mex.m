% Generate mexw64 for static/dynamic open/closed-loop simulink testing
mydir = pwd;

idcs   = strfind(mydir,filesep);
oneupdir = mydir(1:idcs(end)-1);

idcs   = strfind(oneupdir,filesep);
twoupdir = oneupdir(1:idcs(end)-1);

idcs   = strfind(twoupdir,filesep);
rootdir = twoupdir(1:idcs(end)-1);
gen_sfundir = rootdir+"\test\sl\generate_mex\gen_sfun";

clear mydir idcs oneupdir twoupdir;

SrcPaths = {convertStringsToChars(rootdir+"\src"), convertStringsToChars(rootdir+"\test\sl\generate_mex\cpp2sl"), convertStringsToChars(rootdir+"\test\sl\generate_mex\cpp2sl\fct")};
IncPaths = {convertStringsToChars(rootdir+"\include"), convertStringsToChars(rootdir+"\test\sl\generate_mex\cpp2sl"), convertStringsToChars(rootdir+"\test\sl\generate_mex\cpp2sl\fct")};

GeneralSourceFiles={'interface_matlab_class.cpp',...
    'tq_distbn_srv.cpp'};
    
GeneralHeaderFiles={'interface_matlab_class.hpp',...
 'tq_distbn_srv.hpp'};


build_tq_distbn_srv = true;
        

if (build_tq_distbn_srv)

    tq_distbn_srv = legacy_code('initialize');
    tq_distbn_srv.SFunctionName = 'sfun_tq_distbn_srv';
    tq_distbn_srv.Options.language = 'C++';
    
    tq_distbn_srv.StartFcnSpec  = 'create_tq_distbn_srv()';
    tq_distbn_srv.OutputFcnSpec = 'tq_distbn_srv_output(single u1, single u2, single y1[1], single y2[1])';
   
    tq_distbn_srv.TerminateFcnSpec = 'delete_tq_distbn_srv()';
    
    tq_distbn_srv.SourceFiles = ['test_tq_distbn_srv_sl.cpp' GeneralSourceFiles];
    tq_distbn_srv.HeaderFiles = ['test_tq_distbn_srv_sl.hpp' GeneralHeaderFiles];
    
    tq_distbn_srv.SrcPaths = SrcPaths;
    tq_distbn_srv.IncPaths = IncPaths;
    
    legacy_code('sfcn_cmex_generate', tq_distbn_srv);
    legacy_code('compile', tq_distbn_srv);
    
    movefile("sfun_tq_distbn_srv.cpp",      gen_sfundir);
    movefile("sfun_tq_distbn_srv.mexw64",   gen_sfundir);
    
    clear tq_distbn_srv;
end

clear rootdir...
      gen_sfundir...
      SrcPaths...
      IncPaths...
      GeneralSourceFiles...
      GeneralHeaderFiles...
      build_tq_distbn_srv;