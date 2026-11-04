/* func_80161cf0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80162093  size 932 B
 * body sha256 eb0c1cd844d4956e89cebafcbe9ae27fa3c26c46321c456f3314c5692a99cdb5
 * provider record sha256 f20bc72f4b9d0696eae814de9ce244a6271fde02783595f27029c7fa279acda1
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  byte bVar1;
  uint *in_a0;
  uint uVar2;
  undefined1 *puVar3;
  
  puVar3 = &DAT_800e1158;
  if ((_DAT_800e110c & 0x10000000) != 0) {
    if ((in_a0[0xa4] & 0xc0000000) == 0x40000000) {
      puVar3 = (undefined1 *)(_DAT_800e13ec + 0x28);
    }
    func_0x8006568c((int)*(short *)(puVar3 + 2),(int)*(short *)(puVar3 + 10));
  }
  func_0x800653d0();
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if (((*(ushort *)((int)in_a0 + 0x1aa) & 1) != 0) || ((*(ushort *)((int)in_a0 + 0x2b6) & 2) != 0)
       ) {
      *in_a0 = *in_a0 | 0x4000000;
    }
    uVar2 = *in_a0;
    if ((uVar2 & 0xc000000) == 0x4000000) {
      *in_a0 = uVar2 | 0x4000000;
      if (((_DAT_800e12da & 0xfff) != 0xe) && ((_DAT_800e12da & 0xfff) != 0x12)) {
        if (((_DAT_800e1320 & 0x8000) != 0) && (_DAT_800e115c + -0x5dc < (int)in_a0[0xb])) {
          *in_a0 = uVar2 & 0xfbffffff;
        }
        if (((_DAT_800e1320 & 0x4000) != 0) && (_DAT_800e115c + -1000 < (int)in_a0[0xb])) {
          *in_a0 = *in_a0 & 0xfbffffff;
        }
      }
    }
    if (*(char *)((int)in_a0 + 0x2d5) != '\0') {
      *(char *)((int)in_a0 + 0x2d5) = *(char *)((int)in_a0 + 0x2d5) + -1;
    }
    if (*(char *)((int)in_a0 + 0x2da) != '\0') {
      *(char *)((int)in_a0 + 0x2da) = *(char *)((int)in_a0 + 0x2da) + -1;
    }
    if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
    }
    if (*(char *)(in_a0 + 0xb3) != '\0') {
      *(char *)(in_a0 + 0xb3) = *(char *)(in_a0 + 0xb3) + -1;
      _DAT_800e1128 = _DAT_800e1128 | 0x100;
    }
    (*(code *)(&PTR_FUN_8016e150)[*(byte *)(in_a0 + 1)])();
    FUN_8016d960();
    in_a0[0x94] = (uint)&DAT_800e1130;
    *(short *)((int)in_a0 + 0x2d2) = *(short *)((int)in_a0 + 0x2d2) + 1;
    bVar1 = *(byte *)(in_a0 + 0x97);
    *(byte *)(in_a0 + 0x97) = bVar1 & 0xfd;
    if (((*(ushort *)((int)in_a0 + 0x1aa) & 0x4000) != 0) ||
       ((*(ushort *)((int)in_a0 + 0x2b6) & 0x200) != 0)) {
      *(byte *)(in_a0 + 0x97) = bVar1 & 0xfd | 2;
    }
    func_0x800347b0();
    FUN_8016cec4();
    if ((*(short *)(in_a0 + 0x6a) != 0) && (-1 < _DAT_800e1322)) {
      if ((*(int *)(in_a0[0x8d] + 0x50) + -500 < (int)*(short *)(in_a0 + 0x6a)) &&
         (((*(byte *)((int)in_a0 + 0x1e9) & 0xf) == 1 && (10 < *(short *)(in_a0 + 0x78))))) {
        FUN_8016d778();
      }
      if ((*(uint *)in_a0[0x85] & 0xf8000000) == 0x8000000) {
        FUN_8016d778();
      }
      if ((*(uint *)in_a0[0x85] & 0xf8000000) == 0x48000000) {
        FUN_8016d778();
      }
    }
    FUN_8016d348();
    in_a0[0xb1] = in_a0[1];
    func_0x80033648();
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
