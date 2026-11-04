/* FUN_801637c8
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801637c8  body 0x801637c8..0x8016395f  size 408 B
 * body sha256 aacda8d57817cb6046936127e68e8e11ff1352ac9543441e17cee6b12fa38098
 * provider record sha256 643fcab30f6c76b8b00f3816a5e3d009c4c812abcc1e0a7eeb41deef3efda650
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801637c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if ((*(char *)(param_1 + 0x2ca) == '\0') && (*(uint *)(param_1 + 0x28c) < 2000)) {
    iVar1 = func_0x80032e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                            *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x300);
    uVar2 = 0x1020000;
    if (iVar1 == 0) {
      uVar2 = 0x1090000;
    }
    goto LAB_80163944;
  }
  if (4000 < *(uint *)(param_1 + 0x28c)) {
    if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) {
      uVar3 = func_0x80033604(param_1);
      uVar2 = 0x10a0000;
      if (2 < (uVar3 & 7)) {
        uVar3 = func_0x80033604();
        uVar2 = 0x1140000;
        if ((uVar3 & 2) == 0) {
          uVar2 = 0x1080000;
        }
      }
      *(undefined4 *)(param_1 + 4) = uVar2;
      if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) goto LAB_80163900;
    }
    uVar3 = func_0x80033604(param_1);
    uVar2 = 0x10a0000;
    if (1 < (uVar3 & 7)) {
      uVar2 = 0x1140000;
    }
    *(undefined4 *)(param_1 + 4) = uVar2;
  }
LAB_80163900:
  func_0x800334c8(param_1,param_2,param_3,1);
  func_0x80032b5c(param_1,0);
  func_0x8008a994(param_1,param_2,param_3,0x10100);
  uVar2 = 0x10f0000;
  if (*(char *)(param_1 + 0x1e9) != '.') {
    return;
  }
LAB_80163944:
  *(undefined4 *)(param_1 + 4) = uVar2;
  return;
}
