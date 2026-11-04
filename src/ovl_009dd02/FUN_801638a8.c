/* FUN_801638a8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801638a8  body 0x801638a8..0x801639cf  size 296 B
 * body sha256 318b0f8fa1dc0f005635f7d66511e837b3784be6d0c1445bd5d02d2aa95e526d
 * provider record sha256 7777f23e7bb405181b40ed21cbf023cdfb37905a1a0cb292441f6d307913ac27
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801638a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if ((bVar1 == 2) && (*(char *)(param_1 + 0x2c7) != '\0')) {
        FUN_801639d0(param_1,param_2,param_3);
      }
      goto LAB_801639a8;
    }
    if ((bVar1 != 0) || (*(char *)(param_1 + 0x2c7) == '\0')) goto LAB_801639a8;
  }
  *(undefined1 *)(param_1 + 7) = 2;
  *(undefined1 *)(param_1 + 0x2c6) = 2;
  *(undefined1 *)(param_1 + 0x2c7) = 0;
  *(undefined1 *)(param_1 + 0x2c8) = 0x20;
  local_14 = 0;
  local_16 = 0;
  local_18 = 0;
  func_0x80037780((uint)*(byte *)(param_1 + 0x2c0) << 0x10 | 0x1d000c00,
                  (int)(((uint)*(ushort *)(param_1 + 0x66) +
                         (uint)*(ushort *)(*(int *)(param_1 + 0x234) + 0xd92) +
                        (uint)*(byte *)(param_1 + 0x2cd) * 0x800) * 0x10000) >> 0x10,
                  *(int *)(param_1 + 0x234) + 0x1060,&local_18);
  func_0x80077d18(3,param_1);
LAB_801639a8:
  func_0x80089d54(param_1,param_2,param_3,0x40);
  return;
}
