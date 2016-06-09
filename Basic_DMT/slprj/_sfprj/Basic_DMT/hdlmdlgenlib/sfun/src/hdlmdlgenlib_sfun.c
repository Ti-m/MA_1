/* Include files */

#include "hdlmdlgenlib_sfun.h"
#include "hdlmdlgenlib_sfun_debug_macros.h"
#include "c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib.h"
#include "c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib.h"
#include "c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib.h"
#include "c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib.h"
#include "c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib.h"
#include "c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib.h"
#include "c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib.h"
#include "c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _hdlmdlgenlibMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void hdlmdlgenlib_initializer(void)
{
}

void hdlmdlgenlib_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hdlmdlgenlib_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==5) {
    if (!strcmp(specsCksum, "1TmN54LPk8kIORPc9sIuQE")) {
      c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "J9ZL1xBj1yQicYgY8ZGPTH")) {
      c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "MH4rdTzZM3AzjP03jr8sgD")) {
      c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "RSKrmfct3MY4yuXQLbkmzC")) {
      c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "UPbFSQSsluEqmANVGQ0wVH")) {
      c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "YReYssZ4nohWJHGDbcUR4F")) {
      c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "f5AKlsTFv2bRDspNtV5RyE")) {
      c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "pD5K2tCy1Vk2Pud2nfMlXG")) {
      c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    return 0;
  }

  return 0;
}

extern void sf_hdlmdlgenlib_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_hdlmdlgenlib_process_check_sum_call( int nlhs, mxArray * plhs[],
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
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"hdlmdlgenlib")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2643333633U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3165109067U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3089404145U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2422947490U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 5:
            {
              extern void
                sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_check_sum(mxArray *
                plhs[]);
              sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hdlmdlgenlib_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
     case 5:
      {
        if (strcmp(aiChksum, "yaJX5klncSD387p8cxFezG") == 0) {
          extern mxArray
            *sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_autoinheritance_info();
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

unsigned int sf_hdlmdlgenlib_get_eml_resolved_functions_info( int nlhs, mxArray *
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
     case 5:
      {
        extern const mxArray
          *sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_eml_resolved_functions_info
          ();
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

unsigned int sf_hdlmdlgenlib_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
     case 5:
      {
        if (strcmp(tpChksum, "1TmN54LPk8kIORPc9sIuQE") == 0) {
          extern mxArray
            *sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_third_party_uses_info();
          break;
        }

        if (strcmp(tpChksum, "J9ZL1xBj1yQicYgY8ZGPTH") == 0) {
          extern mxArray
            *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_third_party_uses_info();
          break;
        }

        if (strcmp(tpChksum, "MH4rdTzZM3AzjP03jr8sgD") == 0) {
          extern mxArray
            *sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_third_party_uses_info();
          break;
        }

        if (strcmp(tpChksum, "RSKrmfct3MY4yuXQLbkmzC") == 0) {
          extern mxArray
            *sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_third_party_uses_info();
          break;
        }

        if (strcmp(tpChksum, "UPbFSQSsluEqmANVGQ0wVH") == 0) {
          extern mxArray
            *sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_third_party_uses_info();
          break;
        }

        if (strcmp(tpChksum, "YReYssZ4nohWJHGDbcUR4F") == 0) {
          extern mxArray
            *sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_third_party_uses_info();
          break;
        }

        if (strcmp(tpChksum, "f5AKlsTFv2bRDspNtV5RyE") == 0) {
          extern mxArray
            *sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_third_party_uses_info();
          break;
        }

        if (strcmp(tpChksum, "pD5K2tCy1Vk2Pud2nfMlXG") == 0) {
          extern mxArray
            *sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_hdlmdlgenlib_jit_fallback_info( int nlhs, mxArray * plhs[], int
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
     case 5:
      {
        if (strcmp(tpChksum, "1TmN54LPk8kIORPc9sIuQE") == 0) {
          extern mxArray
            *sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_jit_fallback_info();
          break;
        }

        if (strcmp(tpChksum, "J9ZL1xBj1yQicYgY8ZGPTH") == 0) {
          extern mxArray
            *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_jit_fallback_info();
          break;
        }

        if (strcmp(tpChksum, "MH4rdTzZM3AzjP03jr8sgD") == 0) {
          extern mxArray
            *sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_jit_fallback_info();
          break;
        }

        if (strcmp(tpChksum, "RSKrmfct3MY4yuXQLbkmzC") == 0) {
          extern mxArray
            *sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_jit_fallback_info();
          break;
        }

        if (strcmp(tpChksum, "UPbFSQSsluEqmANVGQ0wVH") == 0) {
          extern mxArray
            *sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_jit_fallback_info();
          break;
        }

        if (strcmp(tpChksum, "YReYssZ4nohWJHGDbcUR4F") == 0) {
          extern mxArray
            *sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_jit_fallback_info();
          break;
        }

        if (strcmp(tpChksum, "f5AKlsTFv2bRDspNtV5RyE") == 0) {
          extern mxArray
            *sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_jit_fallback_info();
          break;
        }

        if (strcmp(tpChksum, "pD5K2tCy1Vk2Pud2nfMlXG") == 0) {
          extern mxArray
            *sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_jit_fallback_info(void);
          plhs[0] = sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_hdlmdlgenlib_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 5:
      {
        if (strcmp(tpChksum, "1TmN54LPk8kIORPc9sIuQE") == 0) {
          extern mxArray
            *sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }

        if (strcmp(tpChksum, "J9ZL1xBj1yQicYgY8ZGPTH") == 0) {
          extern mxArray
            *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }

        if (strcmp(tpChksum, "MH4rdTzZM3AzjP03jr8sgD") == 0) {
          extern mxArray
            *sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }

        if (strcmp(tpChksum, "RSKrmfct3MY4yuXQLbkmzC") == 0) {
          extern mxArray
            *sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }

        if (strcmp(tpChksum, "UPbFSQSsluEqmANVGQ0wVH") == 0) {
          extern mxArray
            *sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }

        if (strcmp(tpChksum, "YReYssZ4nohWJHGDbcUR4F") == 0) {
          extern mxArray
            *sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }

        if (strcmp(tpChksum, "f5AKlsTFv2bRDspNtV5RyE") == 0) {
          extern mxArray
            *sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }

        if (strcmp(tpChksum, "pD5K2tCy1Vk2Pud2nfMlXG") == 0) {
          extern mxArray
            *sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_hdlmdlgenlib_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 5:
    {
      if (strcmp(tpChksum, "1TmN54LPk8kIORPc9sIuQE") == 0) {
        extern mxArray
          *sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_1TmN54LPk8kIORPc9sIuQE_hdlmdlgenlib_get_post_codegen_info();
        return;
      }

      if (strcmp(tpChksum, "J9ZL1xBj1yQicYgY8ZGPTH") == 0) {
        extern mxArray
          *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_post_codegen_info();
        return;
      }

      if (strcmp(tpChksum, "MH4rdTzZM3AzjP03jr8sgD") == 0) {
        extern mxArray
          *sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_MH4rdTzZM3AzjP03jr8sgD_hdlmdlgenlib_get_post_codegen_info();
        return;
      }

      if (strcmp(tpChksum, "RSKrmfct3MY4yuXQLbkmzC") == 0) {
        extern mxArray
          *sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_RSKrmfct3MY4yuXQLbkmzC_hdlmdlgenlib_get_post_codegen_info();
        return;
      }

      if (strcmp(tpChksum, "UPbFSQSsluEqmANVGQ0wVH") == 0) {
        extern mxArray
          *sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_UPbFSQSsluEqmANVGQ0wVH_hdlmdlgenlib_get_post_codegen_info();
        return;
      }

      if (strcmp(tpChksum, "YReYssZ4nohWJHGDbcUR4F") == 0) {
        extern mxArray
          *sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_get_post_codegen_info();
        return;
      }

      if (strcmp(tpChksum, "f5AKlsTFv2bRDspNtV5RyE") == 0) {
        extern mxArray
          *sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_f5AKlsTFv2bRDspNtV5RyE_hdlmdlgenlib_get_post_codegen_info();
        return;
      }

      if (strcmp(tpChksum, "pD5K2tCy1Vk2Pud2nfMlXG") == 0) {
        extern mxArray
          *sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_post_codegen_info(void);
        plhs[0] =
          sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void hdlmdlgenlib_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _hdlmdlgenlibMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "hdlmdlgenlib","sfun",1,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _hdlmdlgenlibMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_hdlmdlgenlibMachineNumber_,
    0);
}

void hdlmdlgenlib_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_hdlmdlgenlib_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("hdlmdlgenlib",
      "Basic_DMT");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_hdlmdlgenlib_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
