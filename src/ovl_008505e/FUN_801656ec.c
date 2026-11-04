/* FUN_801656ec
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801656ec  body 0x801656ec..0x8016579b  size 176 B
 * body sha256 75d9b9178d40756f1e226d9b131d444430ad972d917f872ba96ac8aae498fabf
 * provider record sha256 416518f004202015c40bd2e39e90b8651f3714846f94f3de5d96f906f2efe295
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801656ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 2 - *(byte *)(param_1 + 0x26e) / 3;
  *(char *)(param_1 + 699) = (char)uVar1;
  uVar2 = 0;
  if ((uVar1 & 0xff) != 0) {
    do {
      uVar2 = uVar2 + 1;
      uVar1 = func_0x80033604();
      FUN_80166980(param_1,uVar1 & 0xf,8);
    } while (uVar2 < *(byte *)(param_1 + 699));
  }
  *(undefined1 *)(param_1 + 5) = 1;
  FUN_80164d5c(param_1,param_2,param_3);
  return;
}
