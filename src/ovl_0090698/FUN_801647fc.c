/* FUN_801647fc
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801647fc  body 0x801647fc..0x8016490f  size 276 B
 * body sha256 51fd0919a0ceb71689f29eb41731b844cf77d4734a5acd73419007cb85bd6179
 * provider record sha256 255b326899c677225b2d256d87afb80bcb4371af410addc07b93021844b40bab
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801647fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar4;
  int iVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      iVar2 = 0x1090000;
      if ((*(char *)(param_1 + 5) != '\x01') &&
         (iVar2 = 0x1090000, *(byte *)(param_1 + 0x26e) / 3 != 0)) {
        uVar3 = func_0x80033604();
        iVar2 = (uint)(byte)(&DAT_80167ee8)[uVar3 & 7] * 0x10000 + 0x1000000;
      }
      *(int *)(param_1 + 4) = iVar2;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000300;
    if (*(char *)(param_1 + 0x2d8) != '\x01') {
      FUN_8016703c(param_1,0,0);
    }
  }
  cVar4 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
  return;
}
