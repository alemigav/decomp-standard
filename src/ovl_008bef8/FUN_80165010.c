/* FUN_80165010
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165010  body 0x80165010..0x801651d7  size 456 B
 * body sha256 b91f30e92d9f89bb488a3e9d3ea0558feccfd81d14a24225cb668fea68a5e2fe
 * provider record sha256 f748b45d511c79ec544d1e13d76d7a0a7459cb3b441316517cf73f6398a6a4bd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165010(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short local_18 [4];
  
  iVar5 = *(int *)(param_1 + 0x234);
  bVar1 = *(byte *)(param_1 + 0x2c9);
  if (bVar1 == 1) {
    *(undefined4 *)(iVar5 + 0xaac) = 0x800e9028;
    *(undefined4 *)(iVar5 + 0xa64) = *(undefined4 *)(iVar5 + 0xa94);
    *(undefined4 *)(iVar5 + 0xa68) = *(undefined4 *)(iVar5 + 0xa98);
    *(undefined4 *)(iVar5 + 0xa6c) = *(undefined4 *)(iVar5 + 0xa9c);
    local_18[2] = 0;
    local_18[1] = 0;
    local_18[0] = 0;
    func_0x800838c0(iVar5 + 0xa64,iVar5 + 0xaa0,iVar5 + 0xa80,local_18);
    DAT_80166356 = -700;
    DAT_80166358 = -500;
    DAT_8016635a = 0x46;
    DAT_8016635c = -0xd2;
    DAT_8016635e = 10;
    *(char *)(param_1 + 0x2c9) = *(char *)(param_1 + 0x2c9) + '\x01';
  }
  else {
    if (bVar1 < 2) {
      return;
    }
    if (bVar1 != 2) {
      return;
    }
  }
  sVar3 = func_0x80032d14((int)*(short *)(iVar5 + 0xa66),(int)*(short *)(iVar5 + 0xa6e),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  local_18[2] = 0;
  local_18[0] = DAT_80166356;
  func_0x800837d0((int)sVar3,local_18,local_18);
  sVar2 = DAT_8016635c;
  sVar3 = DAT_8016635a;
  iVar4 = (int)DAT_80166358;
  *(int *)(iVar5 + 0xa64) = *(int *)(iVar5 + 0xa64) + (int)local_18[0];
  *(int *)(iVar5 + 0xa68) = *(int *)(iVar5 + 0xa68) + iVar4;
  *(short *)(iVar5 + 0xaa4) = *(short *)(iVar5 + 0xaa4) + sVar2;
  DAT_80166358 = DAT_80166358 + sVar3;
  *(int *)(iVar5 + 0xa6c) = *(int *)(iVar5 + 0xa6c) + (int)local_18[2];
  if (-1 < *(int *)(iVar5 + 0xa68)) {
    *(undefined4 *)(iVar5 + 0xa68) = 0;
    *(undefined1 *)(param_1 + 0x2c9) = 0;
  }
  DAT_8016635c = DAT_8016635c + DAT_8016635e;
  if (-1 < (int)((uint)DAT_8016635c << 0x10)) {
    DAT_8016635c = 0;
    DAT_8016635e = 0;
  }
  return;
}
