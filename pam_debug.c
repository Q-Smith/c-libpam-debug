#include <stdio.h>
#include <stdlib.h>
#include <security/pam_modules.h>

static int pam_debug(const char *function_name, pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  fprintf(stderr, "PAM DEBUG: Called %s\n", function_name);
  return PAM_SUCCESS;
}

PAM_EXTERN
int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  // get username and password
  //int pam_err = pam_get_user(pamh, &username, NULL);
  //pam_err = pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL);
  return pam_debug(__FUNCTION__, pamh, flags, argc, argv);
}

PAM_EXTERN
int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return pam_debug(__FUNCTION__, pamh, flags, argc, argv);
}

PAM_EXTERN
int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return pam_debug(__FUNCTION__, pamh, flags, argc, argv);
}

PAM_EXTERN
int pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return pam_debug(__FUNCTION__, pamh, flags, argc, argv);
}