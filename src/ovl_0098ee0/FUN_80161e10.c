/* FUN_80161e10
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80161e10  body 0x80161e10..0x80161f0b  size 252 B
 * body sha256 a7e597c16f0b05e146705c17e3aecd0724f3d137f467b925c1fa485f7cf87c47
 * provider record sha256 06bc559adbe9f8d92d5961d7436526727ba3e0f8b4a07c2d4c8b08ff2f153b68
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80161e10(int param_1,int param_2,ushort param_3,ushort param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = param_2 * 0x178 + *(int *)(param_1 + 0x234);
  iVar1 = _DAT_800e1158 - *(int *)(iVar5 + 0x4c);
  iVar2 = _DAT_800e1160 - *(int *)(iVar5 + 0x54);
  uVar3 = func_0x80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
  *(undefined2 *)(param_1 + 0x2b8) = *(undefined2 *)(iVar5 + 0x4e);
  *(undefined2 *)(param_1 + 0x2ba) = *(undefined2 *)(iVar5 + 0x56);
  if (*(byte *)(param_1 + 0x1e9) < param_3) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    if ((*(byte *)(param_1 + 0x1e9) <= param_4) && (uVar4 = 0, *(short *)(param_1 + 500) == 0)) {
      if (param_5 < uVar3) {
        uVar4 = 0;
      }
      else {
        *(undefined2 *)(param_1 + 500) = 1;
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}
