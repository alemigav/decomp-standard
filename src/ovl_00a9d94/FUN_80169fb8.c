/* FUN_80169fb8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80169fb8  body 0x80169fb8..0x8016a407  size 1104 B
 * body sha256 92bd88390e1175f96efed383d18dda05a4a8e0e4c460d234e12c98fdee5f84c7
 * provider record sha256 ca12d6d2c29e7e8dbff5d58ab9981a97d699ffdd14851b56daf36ad07ccb474d
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80169fb8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  uint *puVar8;
  uint *puVar9;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined1 *)(param_1 + 6) = 1;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    if (*(char *)(param_1 + 5) == '\0') {
      iVar3 = *(int *)(param_1 + 0x234);
      local_28 = *(undefined2 *)(iVar3 + 0xbde);
      local_26 = *(undefined2 *)(iVar3 + 0xbe2);
      local_24 = *(undefined2 *)(iVar3 + 0xbe6);
      puVar9 = *(uint **)(param_1 + 0x234);
      puVar8 = puVar9 + 0xe;
      func_0x80037780(8000,(int)*(short *)(param_1 + 0x66),puVar8,&local_28);
      func_0x80037780(0x21f40,(int)*(short *)(param_1 + 0x66),puVar8,&local_28);
      func_0x80037780(0x21f40,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,puVar8,
                      &local_28);
      puVar9[0x4c] = 0x40;
      puVar9[0x4d] = 0x30;
      *puVar9 = *puVar9 | 0x80;
      iVar3 = *(int *)(param_1 + 0x234);
      bVar1 = *(byte *)(param_1 + 5);
      iVar6 = *(int *)(_DAT_800e13f0 + 0x234);
      *(uint *)(iVar3 + 0xbc0) = *(uint *)(iVar3 + 0xbc0) | 0x4000;
      iVar6 = iVar6 + ((uint)bVar1 * -5 + 0x12) * 0x178;
      *(int *)(iVar3 + 0xc24) = iVar6 + 0x38;
      *(int *)(iVar3 + 0xcec) = iVar6;
      *(undefined4 *)(iVar3 + 0xbdc) = 0;
      *(undefined4 *)(iVar3 + 0xbe0) = 600;
      *(uint *)(iVar3 + 0xbe4) = (uint)*(byte *)(param_1 + 5) * -600 + 300;
    }
    else {
      iVar6 = *(int *)(param_1 + 0x234);
      local_28 = 0;
      local_26 = 0xfed4;
      local_24 = 0;
      iVar3 = iVar6 + 0x1b0;
      func_0x80037780(8000,(int)*(short *)(param_1 + 0x66),iVar3,&local_28);
      func_0x80037780(0x21f40,(int)*(short *)(param_1 + 0x66),iVar3,0);
      func_0x80037780(0x21f40,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar3,0
                     );
      *(uint *)(iVar6 + 0x178) = *(uint *)(iVar6 + 0x178) | 0x80;
      *(undefined4 *)(iVar6 + 0x2a8) = 0x40;
      *(undefined4 *)(iVar6 + 0x2ac) = 0x30;
      func_0x80037780(8000,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0xbf8,0);
      func_0x80037780(8000,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0xd70,0);
      func_0x80037780(8000,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x11d8,0);
    }
    func_0x80052bd0(2,0);
    func_0x80052bd0(6,10);
    func_0x80052bd0(10,0x17);
    func_0x80052bd0(6,0x28);
    func_0x80052c6c(0x1e,0xfa,0);
    func_0x80052d10(0x78,0xfa,0,0x1e);
    func_0x80052bd0(3,0x48);
    func_0x80052c6c(8,0xfa,0x48);
  }
  if (*(char *)(param_1 + 5) == '\0') {
    if ((0x3b < *(byte *)(param_1 + 0x1e9)) || ((*(byte *)(param_1 + 0x1e9) & 1) == 0))
    goto LAB_8016a3a8;
    iVar3 = *(int *)(param_1 + 0x234);
    uVar4 = func_0x80033604(param_1);
    uVar5 = func_0x80033604();
    func_0x80037780((uVar4 & 1) << 0x10 | (uVar5 & 0xff) * 4 + 2000,0,iVar3 + 0xbf8,0);
    local_28 = 0;
    local_26 = 0xfda8;
    local_24 = 0;
    iVar3 = *(int *)(param_1 + 0x234);
    uVar4 = func_0x80033604();
    uVar5 = func_0x80033604();
    uVar4 = (uVar4 & 1) << 0x10 | (uVar5 & 0xff) * 8 + 2000;
    puVar7 = &local_28;
    sVar2 = *(short *)(param_1 + 0x66);
    iVar3 = iVar3 + 0x38;
  }
  else {
    if ((0x3b < *(byte *)(param_1 + 0x1e9)) || ((*(byte *)(param_1 + 0x1e9) & 1) == 0))
    goto LAB_8016a3a8;
    iVar3 = *(int *)(param_1 + 0x234);
    uVar4 = func_0x80033604(param_1);
    uVar5 = func_0x80033604();
    uVar4 = (uVar4 & 1) << 0x10 | (uVar5 & 0xff) * 8 + 4000;
    puVar7 = (undefined2 *)0x0;
    sVar2 = *(short *)(param_1 + 0x66);
    iVar3 = iVar3 + 0x1b0;
  }
  func_0x80037780(uVar4,(int)sVar2,iVar3,puVar7);
LAB_8016a3a8:
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar3 != 0) {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  func_0x80032b5c(param_1,0);
  return;
}
