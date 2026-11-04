/* func_80161cf0
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x801620b3  size 964 B
 * body sha256 105814f30457ed3402179baaf1c71ab17a7b91ead74f7745a8b54dbf501e048b
 * provider record sha256 bad1a7559a8e1e2c5f034b02fa73e5b8cca41759322d6107d77eb5157e8c2b89
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  short sVar1;
  byte bVar3;
  uint uVar2;
  uint *in_a0;
  int iVar4;
  undefined4 *puVar5;
  ushort local_18;
  
  func_0x800653d0(in_a0,&DAT_800e1158,0,0);
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
    }
    if ((*(byte *)((int)in_a0 + 0x2be) & 0x7f) != 0) {
      *(byte *)((int)in_a0 + 0x2be) = *(byte *)((int)in_a0 + 0x2be) - 1;
    }
    (*(code *)(&PTR_FUN_80167f60)[*(byte *)(in_a0 + 1)])();
    if (*(short *)(in_a0 + 0xad) != 0) {
      *(short *)(in_a0 + 0xad) = *(short *)(in_a0 + 0xad) + -1;
    }
    if (*(char *)((int)in_a0 + 0x2b9) != '\0') {
      *(char *)((int)in_a0 + 0x2b9) = *(char *)((int)in_a0 + 0x2b9) + -1;
    }
    if (*(char *)(in_a0 + 0xb1) != '\0') {
      *(char *)(in_a0 + 0xb1) = *(char *)(in_a0 + 0xb1) + -1;
    }
    if ((*(uint *)in_a0[0x85] & 0x8000000) != 0) {
      bVar3 = func_0x80033604();
      DAT_80167fca = '\x03' - bVar3 % 6;
      bVar3 = func_0x80033604();
      DAT_80167fcb = '\a' - bVar3 % 0xe;
    }
    FUN_80167b18();
    if ((*(ushort *)((int)in_a0 + 0x2ba) & 0x100) != 0) {
      uVar2 = in_a0[0x8d];
      iVar4 = *(int *)(uVar2 + 0x298);
      sVar1 = *(short *)(iVar4 + 0xc);
      *(short *)(iVar4 + 0xc) = sVar1 + (char)(&DAT_80167f80)[*(byte *)((int)in_a0 + 0x2bd)] * -5;
      *(byte *)((int)in_a0 + 0x2bd) = *(char *)((int)in_a0 + 0x2bd) + 1U & 0x3f;
      func_0x80066288();
      func_0x80066554();
      *(short *)(*(int *)(uVar2 + 0x298) + 0xc) = sVar1;
    }
    FUN_80165584();
    FUN_80166220();
    in_a0[0x94] = 0x800e1130;
    if ((*(ushort *)((int)in_a0 + 0x2ba) & 0x4000) == 0) {
      func_0x800349d0();
      local_18 = local_18 & 0xfff;
      if (0x800 < local_18) {
        local_18 = local_18 - 0xfff;
      }
      uVar2 = in_a0[0x8d];
      sVar1 = (short)local_18 / 3;
      *(short *)(uVar2 + 0x34a) = *(short *)(uVar2 + 0x34a) + sVar1;
      func_0x80040e58(uVar2 + 0x348,uVar2 + 0x2f8);
      *(short *)(uVar2 + 0x34a) = *(short *)(uVar2 + 0x34a) - sVar1;
      *(short *)(uVar2 + 0x4c2) = *(short *)(uVar2 + 0x4c2) + sVar1;
      func_0x80040e58(uVar2 + 0x4c0,uVar2 + 0x470);
      *(short *)(uVar2 + 0x4c2) = *(short *)(uVar2 + 0x4c2) - sVar1;
      *(short *)(uVar2 + 0x63a) = *(short *)(uVar2 + 0x63a) + sVar1;
      func_0x80040e58(uVar2 + 0x638,uVar2 + 0x5e8);
      *(short *)(uVar2 + 0x63a) = *(short *)(uVar2 + 0x63a) - sVar1;
    }
    func_0x80033648();
    func_0x8004da40();
    in_a0[0x50] = *(uint *)(in_a0[0x8d] + 0x4b4);
    in_a0[0x52] = *(uint *)(in_a0[0x8d] + 0x4bc);
    in_a0[0x58] = *(uint *)(in_a0[0x8d] + 0x1abc);
    uVar2 = *(uint *)(in_a0[0x8d] + 0x1ac4);
    *(undefined1 *)((int)in_a0 + 0xd) = 0xff;
    in_a0[0x5a] = uVar2;
    puVar5 = (undefined4 *)&DAT_800e13e8;
    if (_DAT_800df93c != (undefined4 *)&DAT_800e13e8) {
      do {
        if ((in_a0 != (uint *)*puVar5) && ((*(uint *)*puVar5 & 1) != 0)) {
          func_0x8004d3a0();
        }
        puVar5 = puVar5 + 1;
      } while (puVar5 != _DAT_800df93c);
    }
    func_0x8004dcb8();
  }
  return;
}
