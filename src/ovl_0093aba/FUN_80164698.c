/* FUN_80164698
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80164698  body 0x80164698..0x8016497f  size 744 B
 * body sha256 5b5180dacbe9c1f1418b9c286ab084596aee0815ef2ad164fe6aad9d16097d3f
 * provider record sha256 c03635adda5682f12cd900d7f0f63e043d7cc36bb406b97b5ebc28fc456c031d
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164698(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  
  if ((*(uint *)(param_1 + 0x28c) < 400) && ((_DAT_800e112a & 6) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x3010100;
    *(undefined1 *)(param_1 + 0x26e) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    uVar2 = func_0x80033604();
    iVar5 = param_1 + 0x14;
    func_0x80037780(0x81fa0,(uVar2 & 0xff) << 4,iVar5,0);
    uVar2 = func_0x80033604();
    func_0x80037780(0x817d0,(uVar2 & 0xff) << 4,iVar5,0);
    uVar2 = func_0x80033604();
    func_0x80037780(0x817d0,(uVar2 & 0xff) << 4,iVar5,0);
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar2 & 7) * 0x10000 + 0x9000000;
    *(undefined2 *)(param_1 + 500) = 0;
    func_0x80052bd0(1,0);
    func_0x80052c6c(5,0x50,0);
    return;
  }
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if (*(uint *)(param_1 + 0x28c) < 0x9c4) {
          *(undefined1 *)(param_1 + 6) = 3;
          *(undefined4 *)(param_1 + 0x1e8) = 0xd000700;
          func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
          return;
        }
        func_0x80089d54(param_1,param_2,param_3,0x100);
        sVar4 = *(short *)(param_1 + 500) + -1;
        *(short *)(param_1 + 500) = sVar4;
        if (sVar4 == -1) {
          *(undefined4 *)(param_1 + 4) = 0x1010000;
          *(undefined2 *)(param_1 + 0x1e0) = 0x50;
          return;
        }
        return;
      }
      if (bVar1 != 3) {
        return;
      }
      func_0x800334c8(param_1,param_2,param_3,0);
      iVar5 = func_0x80089d54(param_1,param_2,param_3,0x200);
      if (iVar5 == 0) {
        func_0x80032b5c(param_1,0);
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(undefined2 *)(param_1 + 0x1e0) = 100;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x40);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80032b5c(param_1,0);
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + *(short *)(param_1 + 500) * -5;
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  if (*(short *)(param_1 + 0x1e0) < 0) {
    *(undefined1 *)(param_1 + 6) = 2;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar3 & 0x1f) + 0x3c;
    *(undefined1 *)(param_1 + 0x206) = 0;
  }
  return;
}
