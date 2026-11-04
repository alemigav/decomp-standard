/* FUN_80009c68
 * image   boot (boot), base 0x80000480
 * address 0x80009c68  body 0x80009c68..0x80009cab  size 68 B
 * body sha256 d4b1144ca6c329ede9c38c64e3c304e576b2d7b05e9f48e3b39f1b0960a1dccd
 * provider record sha256 9e436a184778db5e90eba5fb1421c9ceb630ae5226c6a9f17d4bc302677cf9f7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80009c68(ushort *param_1,short *param_2,short *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = param_1 + 0xe;
  *param_3 = 0;
  *param_2 = 0;
  do {
    uVar1 = *param_1;
    *param_2 = *param_2 + uVar1;
    param_1 = param_1 + 1;
    *param_3 = *param_3 + ~uVar1;
  } while (param_1 < puVar2);
  return 0;
}
