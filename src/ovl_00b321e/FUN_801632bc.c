/* FUN_801632bc
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801632bc  body 0x801632bc..0x8016345b  size 416 B
 * body sha256 5dd6fec08903e00263f05a69b68eb5ad04d18ad6ceb5adf2f16fe44a45db4f51
 * provider record sha256 710f8f0b713b09e82049c5f0200b907d8318dde7aa8bb7028bee5148a8999473
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801632bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  char cVar6;
  undefined1 *puVar7;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar7 = &DAT_800e1130;
  }
  else {
    puVar7 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x66) = *(ushort *)(param_1 + 0x66) & 0xfff;
    iVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)*(short *)(puVar7 + 0x2a),(int)*(short *)(puVar7 + 0x32));
    iVar5 = (iVar3 + 0x800U & 0xc00) + (iVar3 + 0x800U & 0x200) * 2;
    iVar3 = *(short *)(param_1 + 0x66) - iVar5;
    *(short *)(param_1 + 500) = (short)iVar5;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    cVar6 = -0x30;
    *(short *)(param_1 + 0x1f6) = (short)iVar3;
    if (*(short *)(param_1 + 0x66) < *(short *)(param_1 + 500)) {
      cVar6 = '0';
    }
    *(char *)(param_1 + 0x206) = cVar6;
    if ((*(ushort *)(param_1 + 0x1f6) & 0x800) != 0) {
      *(ushort *)(param_1 + 0x1f6) = 0xfff - *(ushort *)(param_1 + 0x1f6);
      *(char *)(param_1 + 0x206) = -cVar6;
    }
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000f00;
  }
  bVar1 = *(byte *)(param_1 + 0x207);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)*(char *)(param_1 + 0x206);
  *(byte *)(param_1 + 0x207) = bVar1 + 1;
  uVar2 = *(undefined2 *)(&LAB_801666e4 + (bVar1 & 7) * 2);
  uVar4 = *(short *)(param_1 + 0x1f6) - 0x30;
  *(ushort *)(param_1 + 0x1f6) = uVar4;
  *(undefined2 *)(param_1 + 100) = uVar2;
  if ((int)((uint)uVar4 << 0x10) < 1) {
    *(undefined1 *)(param_1 + 0x2c4) = 1;
    *(undefined1 *)(param_1 + 5) = 0xb;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x2be) = 1;
    *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(param_1 + 500);
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
