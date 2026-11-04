/* FUN_801655bc
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801655bc  body 0x801655bc..0x8016561b  size 96 B
 * body sha256 443cd241b1084193b08f2bf9d44a87816879a4c49823f56cbf4a14aba4cbb025
 * provider record sha256 aaa8b89b9503dc5e9e6cd9b9e0d60c443b35d72b135f9979d26ef933ad0b08fd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801655bc(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_8016561c();
    if (*(char *)(param_1 + 5) != '\x01') {
      FUN_80166b98(param_1,10,1);
    }
  }
  else {
    FUN_801656c0(param_1);
  }
  return;
}
