/* FUN_8007de80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007de80  body 0x8007de80..0x8007e097  size 536 B
 * body sha256 2030f345eca8ad84f08abf49831477abf219257a7dae7c14a0aa988db2b15343
 * provider record sha256 a2c8cf1132eca0557545e7fc6aa781a5caa48483bf53aa6e11806dffd2ce62e1
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007de80(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  short local_30 [8];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  local_30[0] = 0;
  local_30[1] = 0xe;
  local_30[2] = 10;
  local_30[3] = 0;
  local_30[4] = 0xc;
  if (*(char *)((int)param_1 + 7) == '\0') {
    uVar1 = *(undefined1 *)(param_1 + 2);
    *(undefined1 *)((int)param_1 + 7) = 1;
    sVar2 = local_30[*(ushort *)(param_1 + 0x7c) >> 0xd];
    *(undefined1 *)(param_1 + 2) = 1;
    param_1[0x7a] = sVar2 * 0x1000000 + 0x700;
    FUN_8005bdf4(param_1,*(undefined4 *)(param_1[0x8d] + 0x14e0),3);
    *(undefined1 *)(param_1 + 2) = uVar1;
    FUN_8005ab10(param_1,&PTR_DAT_801103b8 + (uint)(byte)(&DAT_80111024)[*param_1 >> 0x1d] * 2);
    *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) & 0xbfff;
    if ((*(short *)(param_1 + 0x6a) != 0) &&
       (*(short *)(param_1 + 0x6a) < *(short *)((int)param_1 + 0x25e))) {
      FUN_8005c3e8(param_1);
    }
    uVar4 = param_1[0x8d];
    local_20 = 0x8a;
    local_1e = 0x267;
    local_1c = 8;
    FUN_80037780(0x30a0e00,0,uVar4 + 0x1060,&local_20);
    uVar4 = FUN_80037780(0x1000e00,0,uVar4 + 0x1060,&local_20);
    (&DAT_800ebdc3)[(uVar4 & 0xff) * 0x7c] = 1;
  }
  iVar3 = FUN_8005ab48(param_1,*param_1 >> 0x1d | 0x20000,
                       &PTR_DAT_801103b8 + (uint)(byte)(&DAT_80111024)[*param_1 >> 0x1d] * 2);
  if ((iVar3 != 0) && (iVar3 != 0xff)) {
    *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) | 0x4000;
  }
  iVar3 = FUN_80089d54(param_1,param_2,param_3,0x200);
  if (iVar3 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
  }
  return;
}
