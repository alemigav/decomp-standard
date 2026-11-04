/* FUN_800a60f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a60f4  body 0x800a60f4..0x800a61fb  size 264 B
 * body sha256 252caf7df43247c191cced525defe89c9253458d73747651fd08874e07fec331
 * provider record sha256 2c0a9b8485d897f3e62637d489f863008da98e7e5d7c49b0afd1b07800f18e74
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800a618c) */
/* WARNING: Removing unreachable block (ram,0x800a612c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800a60f4(uint param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  
  param_1 = param_1 & 0xff;
  if (param_2 == 0xffffffff) {
    param_2 = 0x40005622;
  }
  uVar2 = param_2 >> 0x18;
  if (param_1 == uVar2) {
    fVar4 = (float)(param_2 & 0xffffff);
  }
  else {
    if (uVar2 < param_1) {
      puVar1 = &DAT_80135d00;
      iVar3 = param_1 - uVar2;
    }
    else {
      puVar1 = &DAT_80135f00;
      iVar3 = uVar2 - param_1;
    }
    fVar4 = (float)(param_2 & 0xffffff) * *(float *)(puVar1 + iVar3 * 4);
  }
  fVar4 = (fVar4 * 4096.0) / (float)_DAT_80147fa4;
  if (2.1474836e+09 <= fVar4) {
    return (int)(fVar4 - 2.1474836e+09) | 0x80000000;
  }
  return (int)fVar4;
}
