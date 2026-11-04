/* FUN_80162cc0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162cc0  body 0x80162cc0..0x80162f77  size 696 B
 * body sha256 d8943e34ed2103988581dce545880804f76cfc60cb001bbbffa5c2ac3e5d731c
 * provider record sha256 b1cbf23cf38424bc091f22d5fa87c30d4831513ee04ce8fed00d3751a333debf
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162cc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  ushort uVar4;
  undefined1 uVar5;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 6) = 3;
        *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + 0xf00;
        uVar4 = func_0x80033604();
        *(ushort *)(param_1 + 500) = (uVar4 & 0xff) + 0x96;
        uVar5 = func_0x80065628();
        *(undefined1 *)(param_1 + 0x2d1) = uVar5;
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x400;
      }
      else if (bVar1 != 3) {
        return;
      }
      func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10
                     );
      func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
      func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                      0x100);
      func_0x80032b5c(param_1,0);
      sVar3 = *(short *)(param_1 + 500);
      *(short *)(param_1 + 500) = sVar3 + -1;
      if (sVar3 == 1) {
        *(undefined1 *)(param_1 + 6) = 0;
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfbff;
      }
      if (*(uint *)(param_1 + 0x28c) < 3000) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfbff;
      }
      if (0x1d4b < *(uint *)(param_1 + 0x28c)) {
        return;
      }
      if ((*(ushort *)(param_1 + 0x1f0) & 0x800) == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfbff;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar2 & 0x1f) * 0x10000 + 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar4 & 0xff) + 0x96;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar4 & 0xff) + 300;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  sVar3 = *(short *)(param_1 + 0x1f6) + -1;
  *(short *)(param_1 + 0x1f6) = sVar3;
  if (sVar3 == -1) {
    if ((*(char *)(param_1 + 0x2d5) == '\0') && (uVar2 = func_0x80033604(), (uVar2 & 1) != 0)) {
      func_0x80077d18(0xb,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar4 & 0xff) + 300;
  }
  if (*(char *)(param_1 + 0x1ea) == '\0') {
    func_0x80033680(param_1,0,1);
  }
  if ((*(short *)(param_1 + 0x1f6) == 0) && (uVar2 = func_0x80033604(), (uVar2 & 1) == 0)) {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  if (*(short *)(param_1 + 500) == 0) {
    if ((*(uint *)(param_1 + 0x28c) < 0x1d4c) && ((*(ushort *)(param_1 + 0x1f0) & 0x800) != 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
    }
    if (*(short *)(param_1 + 500) == 0) {
      return;
    }
  }
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
  return;
}
