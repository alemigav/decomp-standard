/* FUN_80167910
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80167910  body 0x80167910..0x80167abb  size 428 B
 * body sha256 dd8fe9095cb2c6c87240a21d4674240e9a3505a61c46f1c1146a8bb11004928b
 * provider record sha256 94abfdf7e5ca27cbdc340da8264c3aaaa7f3ff63cf2ce82b04f68dcfc48339df
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167910(int param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x80;
  local_18 = 0;
  local_16 = 200;
  local_14 = 0;
  iVar3 = *(int *)(param_1 + 0x234);
  uVar2 = func_0x80033604();
  if ((uVar2 & 1) == 0) {
    func_0x80037780(0x5032710,(int)*(short *)(param_1 + 0x66),iVar3 + 0x38,0);
    iVar3 = *(int *)(param_1 + 0x234);
    if ((*(uint *)(iVar3 + 0x468) & 1) != 0) {
      func_0x80037780(0x5031388,(int)*(short *)(param_1 + 0x66),iVar3 + 0x4a0,&local_18);
      iVar3 = *(int *)(param_1 + 0x234);
    }
    local_16 = 0xff38;
    if ((*(uint *)(iVar3 + 0x8d0) & 1) == 0) goto LAB_80167a24;
    sVar1 = *(short *)(param_1 + 0x66);
    iVar3 = iVar3 + 0x908;
  }
  else {
    func_0x80037780(0x5032710,(int)*(short *)(param_1 + 0x66),iVar3 + 0x38,&local_18);
    iVar3 = *(int *)(param_1 + 0x234);
    if ((*(uint *)(iVar3 + 0xbc0) & 1) != 0) {
      func_0x80037780(0x5031388,(int)*(short *)(param_1 + 0x66),iVar3 + 0xbf8,0);
      iVar3 = *(int *)(param_1 + 0x234);
    }
    if ((*(uint *)(iVar3 + 0x468) & 1) == 0) goto LAB_80167a24;
    sVar1 = *(short *)(param_1 + 0x66);
    iVar3 = iVar3 + 0x4a0;
  }
  func_0x80037780(0x50313e8,(int)sVar1,iVar3,&local_18);
LAB_80167a24:
  if (*(char *)(param_1 + 5) != '\x10') {
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x60) = 0x404040;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1d8) = 0x484848;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x350) = 0x707070;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x7b8) = 0x707070;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xc20) = 0x505050;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xd98) = 0x505050;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xf10) = 0x484848;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1088) = 0x404040;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1200) = 0x505050;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1378) = 0x404040;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x14f0) = 0x404040;
  }
  return;
}
