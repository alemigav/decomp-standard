/* FUN_80162064
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162064  body 0x80162064..0x80162113  size 176 B
 * body sha256 e0ebd38b7bcf24b3aeec4e63d54dd412fe1964b3a32d45f34cb0b556c6459c52
 * provider record sha256 a2f3c4b00c0490df8b94731ec5b8178945a6f9c1ddfc473a0734e184c42aaf49
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162064(int param_1)

{
  byte bVar1;
  int iVar2;
  
  (*(code *)(&PTR_FUN_80163d74)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 0x2c8) == '\0') {
    iVar2 = *(int *)(param_1 + 0x250);
    bVar1 = *(byte *)(iVar2 + 0x2c1);
    if ((bVar1 != 0) && (*(char *)(param_1 + 5) != (byte)((bVar1 & 0x7f) - 1))) {
      if ((bVar1 & 0x80) == 0) {
        if ((*(byte *)(param_1 + 0x2b5) & *(byte *)(iVar2 + 0x2c3)) == 0) {
          return;
        }
      }
      else if (*(char *)(iVar2 + 0x2c3) != *(char *)(param_1 + 0x2b4)) {
        return;
      }
      FUN_80163b24(param_1);
    }
  }
  return;
}
