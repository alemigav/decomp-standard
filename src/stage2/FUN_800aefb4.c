/* FUN_800aefb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aefb4  body 0x800aefb4..0x800af07f  size 204 B
 * body sha256 79d023df85a60934c3e9bfeb47f34c5b66739a97b0eb7f7553dc0bd5038e549a
 * provider record sha256 334734831da37e2285be7f9da7c30cf9e2c89190540f09a3f84f256215005f60
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800aefb4(char param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_80147a58 != 0) {
    piVar1 = (int *)&DAT_80144448;
    do {
      if (*piVar1 == 0) {
LAB_800af044:
        FUN_800a5b14(iVar2);
      }
      else if ((param_1 == '\0') || (*(char *)(piVar1 + 0x13) == '\0')) {
        FUN_800ae1a0(piVar1);
        piVar1[10] = 0;
        piVar1[9] = piVar1[9] & 0xfffffffc;
        FUN_800aebfc(piVar1);
        *piVar1 = 0;
        piVar1[9] = piVar1[9] & 0xfffffffc;
        goto LAB_800af044;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x68;
    } while (iVar2 < (int)(uint)DAT_80147a58);
  }
  return;
}
