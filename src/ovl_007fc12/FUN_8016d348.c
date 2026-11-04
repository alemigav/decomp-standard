/* FUN_8016d348
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016d348  body 0x8016d348..0x8016d777  size 1072 B
 * body sha256 989626dbb49d45f9ebc3be0770440adf357a13559c02c88d60e1aa97e1ad7923
 * provider record sha256 bf4f807a72b875528b4151882f1e6529ad78bcdd466e55276f20f872d004d769
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016d348(int param_1)

{
  short sVar3;
  int iVar1;
  uint uVar2;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_40 = 0x12cfed4;
  local_3c = 0;
  if ((*(ushort *)(param_1 + 0x2b6) & 0x180) == 0) {
    return;
  }
  iVar6 = *(int *)(param_1 + 0x234);
  if ((*(ushort *)(param_1 + 0x2b6) & 0x80) != 0) {
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(uint *)(iVar6 + 0xbc0) = *(uint *)(iVar6 + 0xbc0) | 0x8040;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xff7f | 0x100;
    local_60 = _DAT_800e9028;
    local_5c = _DAT_800e902c;
    local_58 = _DAT_800e9030;
    local_54 = _DAT_800e9034;
    local_50 = _DAT_800e9038;
    local_4c = _DAT_800e903c;
    local_48 = _DAT_800e9040;
    local_44 = _DAT_800e9044;
    func_0x80041454(*(short *)(param_1 + 0x66) + 0x800,&local_60);
    func_0x8004276c(&local_60,&local_40,iVar6 + 0xbe8);
    *(undefined1 *)(iVar6 + 0xcd1) = 2;
  }
  local_60 = _DAT_800e9028;
  local_5c = _DAT_800e902c;
  local_58 = _DAT_800e9030;
  local_54 = _DAT_800e9034;
  local_50 = _DAT_800e9038;
  local_4c = _DAT_800e903c;
  local_48 = _DAT_800e9040;
  local_44 = _DAT_800e9044;
  func_0x80041588(0x80,&local_60);
  func_0x80041320(0x40,&local_60);
  iVar7 = iVar6 + 0xbf8;
  func_0x800424ec(iVar7,&local_60,iVar7);
  local_38 = *(undefined4 *)(iVar6 + 0xc0c);
  local_34 = *(undefined4 *)(iVar6 + 0xc10);
  local_30 = *(undefined4 *)(iVar6 + 0xc14);
  local_2c = *(undefined4 *)(iVar6 + 0xc18);
  *(int *)(iVar6 + 0xc0c) = *(int *)(iVar6 + 0xc0c) + (int)*(short *)(iVar6 + 0xbe8);
  *(int *)(iVar6 + 0xc10) = *(int *)(iVar6 + 0xc10) + (int)*(short *)(iVar6 + 0xbea);
  *(int *)(iVar6 + 0xc14) = *(int *)(iVar6 + 0xc14) + (int)*(short *)(iVar6 + 0xbec);
  sVar3 = func_0x80069f1c(&local_38,100,0x2000,1);
  iVar5 = iVar6 + 0xc0c;
  iVar1 = func_0x800667d4(iVar5,100,1 << (-(*(int *)(iVar6 + 0xc10) / 0x708) & 0x1fU),0x2000);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar6 + 0xc0c) = local_38;
    *(undefined4 *)(iVar6 + 0xc10) = local_34;
    *(undefined4 *)(iVar6 + 0xc14) = local_30;
    *(undefined4 *)(iVar6 + 0xc18) = local_2c;
    sVar3 = func_0x80069f1c(iVar5,100,0x2000,1);
    *(short *)(iVar6 + 0xbe8) = -*(short *)(iVar6 + 0xbe8);
    *(short *)(iVar6 + 0xbec) = -*(short *)(iVar6 + 0xbec);
    uVar2 = func_0x80033604();
    func_0x80037780(1000,(uVar2 & 0xff) << 4,iVar7,0);
    cVar4 = *(char *)(iVar6 + 0xcd1) + -1;
    *(char *)(iVar6 + 0xcd1) = cVar4;
    if (cVar4 == -1) {
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfeff;
      *(undefined4 *)(iVar6 + 0xbc0) = 0;
      goto LAB_8016d744;
    }
    iVar1 = func_0x800667d4(iVar5,100,1 << (-(*(int *)(iVar6 + 0xc10) / 0x708) & 0x1fU),0x2000);
    if (iVar1 != 0) {
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfeff;
      *(undefined4 *)(iVar6 + 0xbc0) = 0;
      goto LAB_8016d744;
    }
  }
  *(short *)(iVar6 + 0xbea) = *(short *)(iVar6 + 0xbea) + 0x32;
  if (*(int *)(iVar6 + 0xc10) <= sVar3 + -200) {
    return;
  }
  *(int *)(iVar6 + 0xc10) = sVar3 + -200;
  *(short *)(iVar6 + 0xbe8) = *(short *)(iVar6 + 0xbe8) >> 1;
  *(short *)(iVar6 + 0xbec) = *(short *)(iVar6 + 0xbec) >> 1;
  *(short *)(iVar6 + 0xbea) = -(*(short *)(iVar6 + 0xbea) >> 2);
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  uVar2 = func_0x80033604();
  func_0x80037780(1000,(uVar2 & 0xff) << 4,iVar6 + 0xbf8,0);
  func_0x80077d18(7,param_1);
  cVar4 = *(char *)(iVar6 + 0xcd1) + -1;
  *(char *)(iVar6 + 0xcd1) = cVar4;
  if (cVar4 != -1) {
    return;
  }
  *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfeff;
  *(undefined4 *)(iVar6 + 0xbc0) = 0;
LAB_8016d744:
  func_0x80038e98(5,3,iVar6 + 0xbf8);
  return;
}
