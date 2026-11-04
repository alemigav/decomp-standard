/* FUN_80166bf0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166bf0  body 0x80166bf0..0x80166cd3  size 228 B
 * body sha256 516e063d82917d02370ac5e1ae0b866d3c37dcf84a3271498aa1482f982026cd
 * provider record sha256 bb8c37548e137f20f5ba67178c2204d3cfe618e8d13b40731c931510e66de6ce
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166bf0(uint *param_1)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)((int)param_1 + 0x2b7) = 1;
        *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80077d18(8,param_1);
    FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,1);
    *param_1 = *param_1 | 2;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  cVar2 = func_0x80036d14(param_1,0x15,0xf,0);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  if (*(short *)((int)param_1 + 0x2d6) < -100) {
    *(short *)((int)param_1 + 0x2d6) = *(short *)((int)param_1 + 0x2d6) + 0x19;
  }
  return;
}
