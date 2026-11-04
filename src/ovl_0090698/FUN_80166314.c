/* FUN_80166314
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166314  body 0x80166314..0x80166427  size 276 B
 * body sha256 c2deeca497a886ccfebedb4fe6c6dff90c6f12fa2578e5b75c90bc5245d8157d
 * provider record sha256 a78e8f3361afdc3ae55a4cf95a48f51b9a0bb59fe29062bef29980ef425e2318
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166314(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((*(char *)(param_1 + 6) == '\0') && (*(char *)(param_1 + 0x2c0) == '\0')) {
    uVar4 = 4;
    if (*(short *)(param_1 + 0x1a8) != 0) {
      uVar4 = 5;
    }
    FUN_8016703c(param_1,0,uVar4);
    uVar3 = 0;
    do {
      uVar1 = func_0x80033604();
      iVar2 = (uVar1 & 0xf) + 3;
      if ((*(uint *)(*(int *)(param_1 + 0x234) + iVar2 * 0x178) & 0x4b) == 1) {
        FUN_8016703c(param_1,iVar2,uVar4);
        FUN_8016703c(param_1,iVar2,5);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 3);
  }
  FUN_80165ec8(param_1,param_2,param_3);
  return;
}
