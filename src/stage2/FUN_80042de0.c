/* FUN_80042de0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042de0  body 0x80042de0..0x80042f9b  size 444 B
 * body sha256 01f539909370de4eadf74b11c2222bd1ac9b37c733602f680a3838a56d895724
 * provider record sha256 9b27c511c5ee411cbcced63d5e52f5a570c99c0348c10f92ff3037e3fe6da94c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80042de0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  short local_10;
  short local_e;
  short local_c;
  
  _DAT_80139a70 = *param_1;
  _DAT_80139a74 = param_1[1];
  FUN_8004276c(&DAT_80139a50,&DAT_80139a70,&local_10);
  local_c = local_c + _DAT_80139a6e;
  if (local_c == 0) {
    local_c = 1;
  }
  iVar1 = (int)(short)(local_10 + _DAT_80139a66) * (uint)DAT_800efc50;
  iVar3 = (int)local_c;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  iVar2 = (int)(short)(local_e + _DAT_80139a6a) * (uint)DAT_800efc52;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar2 == -0x80000000)) {
    trap(0x1800);
  }
  _DAT_80139a84 = local_c;
  fVar4 = (float)-iVar3;
  _DAT_80139a80 = (short)(iVar1 / iVar3) + 0xa0;
  _DAT_80139a82 = (short)(iVar2 / iVar3) + 0x78;
  if (fVar4 < -250.0) {
    _DAT_80139a78 =
         (undefined2)(int)(((fVar4 * DAT_800efc54 + DAT_800efc58) / -fVar4) * 16352.0 + 16352.0);
  }
  else {
    _DAT_80139a78 = 0xffff;
  }
  return;
}
