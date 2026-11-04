/* FUN_80161de0
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80161de0  body 0x80161de0..0x80162023  size 580 B
 * body sha256 cfae0b90aa13b3a7ff260dc1aa0245da2db9331967a0ef362e65699f7bcb8ba1
 * provider record sha256 34e3836aa98de997099867d75582bb5c2197cc9f51278053c080c51409e7605a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161de0(uint *param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = 1;
  iVar3 = 0x178;
  param_1[1] = 0x1000000;
  *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
  *(undefined1 *)(param_1 + 0x97) = 1;
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x2be) = 0;
  *(undefined2 *)((int)param_1 + 0x2c2) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  *(undefined1 *)((int)param_1 + 0x2c5) = 0;
  *(undefined1 *)((int)param_1 + 0x2c6) = 0;
  *(undefined1 *)((int)param_1 + 0x2c7) = 0;
  *param_1 = *param_1 | 0x44a;
  do {
    uVar4 = uVar4 + 1;
    puVar5 = (uint *)(param_1[0x8d] + iVar3);
    *puVar5 = *puVar5 | 0x8000;
    iVar3 = iVar3 + 0x178;
  } while (uVar4 < 3);
  *(undefined2 *)(param_1 + 0x4d) = 0xfe0c;
  *(undefined2 *)((int)param_1 + 0x136) = 500;
  *(undefined2 *)(param_1 + 0x4e) = 500;
  *(undefined2 *)((int)param_1 + 0x13a) = 500;
  *(undefined2 *)(param_1 + 0x4b) = 500;
  *(undefined2 *)((int)param_1 + 0x12e) = 500;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x28a) = 0x4b0;
  uVar4 = func_0x80033604();
  uVar1 = *(ushort *)((int)param_1 + 0x1aa);
  param_1[0x7a] = (uVar4 & 0xf) * 0x10000 + 0x700;
  *(ushort *)((int)param_1 + 0x1aa) = uVar1 | 0x2000;
  if ((uVar1 & 0xff) == 0) {
    func_0x800339dc(param_1 + 0x82,0,0x320190,0,puVar5 + 0x13);
    _DAT_800df934 = FUN_80163c44(param_1,_DAT_800df934);
    DAT_80163d50 = 0;
    *param_1 = *param_1 | 0x80400;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  }
  else {
    puVar5 = (uint *)param_1[0x8d];
    *puVar5 = *puVar5 | 0x4000;
    param_1[0xa9] = (uint)FUN_80161dc4;
    *(undefined1 *)(param_1 + 0xb2) = 0;
    *(undefined1 *)(param_1 + 0xb3) = 0;
    if ((*(ushort *)((int)param_1 + 0x1aa) & 0xff) < 0x20) {
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
      uVar1 = func_0x80033604(param_1 + 0x82);
      sVar2 = (uVar1 & 0xff) << 1;
      *(short *)((int)param_1 + 0x66) = sVar2;
      *(short *)(param_1 + 0xb0) = sVar2;
      FUN_8016375c(param_1,0);
    }
    else {
      *(undefined2 *)(param_1 + 0x19) = 0x400;
      *(undefined1 *)((int)param_1 + 5) = 9;
      *(undefined1 *)(param_1 + 0xb2) = 1;
      *param_1 = *param_1 | 0x18010000;
      func_0x800339dc(param_1 + 0x82,0,0x320190,0,puVar5 + 0x13);
      if (*(short *)((int)param_1 + 0x1aa) == 0x2021) {
        *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
      }
      else {
        *(undefined2 *)((int)param_1 + 0x1f2) = 1;
        *(undefined2 *)((int)param_1 + 0x66) = 0x800;
      }
    }
  }
  return;
}
