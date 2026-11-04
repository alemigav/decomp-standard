/* FUN_80180150
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180150  body 0x80180150..0x801802a7  size 344 B
 * body sha256 2b42ebe3a60eb6fa285f596df1ed23a321ffe93eae0348dbc1f4009160e57c7f
 * provider record sha256 b7c0cec99dbc5772159239d82568332d7d285d3e449df8e6793d5c9988a1b0fb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80180150(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,undefined4 param_8,int param_9,undefined4 param_10)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_5 == 1) {
    if ((param_6 == 0) && (param_9 == 0)) {
      uVar1 = FUN_8017bec8(1);
      puVar2 = (undefined4 *)(param_4 * 4 + param_3);
      *puVar2 = uVar1;
      puVar2[2] = uVar1;
    }
    puVar2 = (undefined4 *)(param_1 + param_4 * 8);
    FUN_801802a8(puVar2,param_2,param_7,param_8,param_9,param_10,0);
    puVar2[4] = *puVar2;
    puVar2[5] = puVar2[1];
  }
  else {
    uVar1 = FUN_8017bec8(1);
    puVar2 = (undefined4 *)(param_4 * 4 + param_3);
    *puVar2 = uVar1;
    FUN_801802a8(param_1 + param_4 * 8,param_2,param_7,param_8,param_9,param_10,0);
    uVar1 = FUN_8017bec8(1);
    puVar2[2] = uVar1;
    FUN_801802a8(param_1 + param_4 * 8 + 0x10,param_2,param_7,param_8,param_9,param_10,0);
  }
  return;
}
