/* Include files */

#include "Basic_DMT_sfun.h"
#include "Basic_DMT_sfun_debug_macros.h"
#include "c3_Basic_DMT.h"
#include "c4_Basic_DMT.h"
#include "c5_Basic_DMT.h"
#include "c7_Basic_DMT.h"
#include "c9_Basic_DMT.h"
#include "c13_Basic_DMT.h"
#include "c14_Basic_DMT.h"
#include "c16_Basic_DMT.h"
#include "c17_Basic_DMT.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Basic_DMTMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Basic_DMT_initializer(void)
{
}

void Basic_DMT_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Basic_DMT_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==3) {
    c3_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Basic_DMT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_Basic_DMT_uses_exported_functions(int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Basic_DMT_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3398597616U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3163274847U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3627786733U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4028937634U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(783671786U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3758558630U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4173171036U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4248464661U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 3:
        {
          extern void sf_c3_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c3_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c4_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c5_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c7_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c9_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c13_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c14_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c16_Basic_DMT_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Basic_DMT_get_check_sum(mxArray *plhs[]);
          sf_c17_Basic_DMT_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3899567622U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1073561369U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4091487703U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3698751343U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4055993410U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2645220327U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3893746202U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(782159071U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Basic_DMT_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 3:
      {
        if (strcmp(aiChksum, "O4JWTbWSreCrQUhJnBsuqE") == 0) {
          extern mxArray *sf_c3_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "otQo3G2eH36MufqBIZbbGF") == 0) {
          extern mxArray *sf_c4_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "br0ANFdrf9WjYv8GTpHEoF") == 0) {
          extern mxArray *sf_c5_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "hRzn4GUISU3r3zY2HtKnIE") == 0) {
          extern mxArray *sf_c7_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c7_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "yJDO4QCIKRsPyjaBULw3kH") == 0) {
          extern mxArray *sf_c9_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c9_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "mYbrBsQFE0vDLFlKySG2P") == 0) {
          extern mxArray *sf_c13_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c13_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "aCDJUyYPyszhwVpeoQ5ntC") == 0) {
          extern mxArray *sf_c14_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c14_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "Fe7NsCsoqng7YLbFDguTgC") == 0) {
          extern mxArray *sf_c16_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c16_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "hRzn4GUISU3r3zY2HtKnIE") == 0) {
          extern mxArray *sf_c17_Basic_DMT_get_autoinheritance_info(void);
          plhs[0] = sf_c17_Basic_DMT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Basic_DMT_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 3:
      {
        extern const mxArray *sf_c3_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray *sf_c16_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_Basic_DMT_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Basic_DMT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Basic_DMT_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 3:
      {
        if (strcmp(tpChksum, "w4jWV5JkZqtqdkUgwxW9YB") == 0) {
          extern mxArray *sf_c3_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c3_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6rBYi7wixSdSxToVa8LORD") == 0) {
          extern mxArray *sf_c4_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c4_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "bVHfmmhq0JN2BgJk1n15TC") == 0) {
          extern mxArray *sf_c5_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c5_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "mrNuRBvJm6nFh7AnJpypWE") == 0) {
          extern mxArray *sf_c7_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c7_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "41QDGowHL6K4I7FEuKmWnH") == 0) {
          extern mxArray *sf_c9_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c9_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "6tpghhZdPl1L2MslTCMwIC") == 0) {
          extern mxArray *sf_c13_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c13_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "3oiy2KY4xYqI3TJ4boZcrG") == 0) {
          extern mxArray *sf_c14_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c14_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "ehadYJODBKjdE9dv2JD8YC") == 0) {
          extern mxArray *sf_c16_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c16_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "yZYYT6n9tffu1xW8SiWXbF") == 0) {
          extern mxArray *sf_c17_Basic_DMT_third_party_uses_info(void);
          plhs[0] = sf_c17_Basic_DMT_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Basic_DMT_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 3:
      {
        if (strcmp(tpChksum, "w4jWV5JkZqtqdkUgwxW9YB") == 0) {
          extern mxArray *sf_c3_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c3_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6rBYi7wixSdSxToVa8LORD") == 0) {
          extern mxArray *sf_c4_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c4_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "bVHfmmhq0JN2BgJk1n15TC") == 0) {
          extern mxArray *sf_c5_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c5_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "mrNuRBvJm6nFh7AnJpypWE") == 0) {
          extern mxArray *sf_c7_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c7_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "41QDGowHL6K4I7FEuKmWnH") == 0) {
          extern mxArray *sf_c9_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c9_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "6tpghhZdPl1L2MslTCMwIC") == 0) {
          extern mxArray *sf_c13_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c13_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "3oiy2KY4xYqI3TJ4boZcrG") == 0) {
          extern mxArray *sf_c14_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c14_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "ehadYJODBKjdE9dv2JD8YC") == 0) {
          extern mxArray *sf_c16_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c16_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "yZYYT6n9tffu1xW8SiWXbF") == 0) {
          extern mxArray *sf_c17_Basic_DMT_jit_fallback_info(void);
          plhs[0] = sf_c17_Basic_DMT_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Basic_DMT_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 3:
      {
        if (strcmp(tpChksum, "w4jWV5JkZqtqdkUgwxW9YB") == 0) {
          extern mxArray *sf_c3_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6rBYi7wixSdSxToVa8LORD") == 0) {
          extern mxArray *sf_c4_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "bVHfmmhq0JN2BgJk1n15TC") == 0) {
          extern mxArray *sf_c5_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "mrNuRBvJm6nFh7AnJpypWE") == 0) {
          extern mxArray *sf_c7_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "41QDGowHL6K4I7FEuKmWnH") == 0) {
          extern mxArray *sf_c9_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "6tpghhZdPl1L2MslTCMwIC") == 0) {
          extern mxArray *sf_c13_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "3oiy2KY4xYqI3TJ4boZcrG") == 0) {
          extern mxArray *sf_c14_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "ehadYJODBKjdE9dv2JD8YC") == 0) {
          extern mxArray *sf_c16_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "yZYYT6n9tffu1xW8SiWXbF") == 0) {
          extern mxArray *sf_c17_Basic_DMT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_Basic_DMT_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Basic_DMT_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 3:
    {
      if (strcmp(tpChksum, "w4jWV5JkZqtqdkUgwxW9YB") == 0) {
        extern mxArray *sf_c3_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c3_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "6rBYi7wixSdSxToVa8LORD") == 0) {
        extern mxArray *sf_c4_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c4_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "bVHfmmhq0JN2BgJk1n15TC") == 0) {
        extern mxArray *sf_c5_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c5_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "mrNuRBvJm6nFh7AnJpypWE") == 0) {
        extern mxArray *sf_c7_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c7_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "41QDGowHL6K4I7FEuKmWnH") == 0) {
        extern mxArray *sf_c9_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c9_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "6tpghhZdPl1L2MslTCMwIC") == 0) {
        extern mxArray *sf_c13_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c13_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 14:
    {
      if (strcmp(tpChksum, "3oiy2KY4xYqI3TJ4boZcrG") == 0) {
        extern mxArray *sf_c14_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c14_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 16:
    {
      if (strcmp(tpChksum, "ehadYJODBKjdE9dv2JD8YC") == 0) {
        extern mxArray *sf_c16_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c16_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 17:
    {
      if (strcmp(tpChksum, "yZYYT6n9tffu1xW8SiWXbF") == 0) {
        extern mxArray *sf_c17_Basic_DMT_get_post_codegen_info(void);
        plhs[0] = sf_c17_Basic_DMT_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Basic_DMT_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Basic_DMTMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Basic_DMT","sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_Basic_DMTMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_Basic_DMTMachineNumber_,0);
}

void Basic_DMT_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Basic_DMT_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Basic_DMT",
      "Basic_DMT");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Basic_DMT_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
