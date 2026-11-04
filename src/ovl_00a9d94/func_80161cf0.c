/* func_80161cf0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80162157  size 1128 B
 * body sha256 1657946fe3ed122f8328a3393cb4969ee24a4d23f117c88eb28b17cdf4acfd45
 * provider record sha256 04d07b80f62e6c249fa1e976cb56b567f123d84286679b78e831a60fa0e4431a
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  ushort uVar1;
  undefined4 uVar2;
  char cVar4;
  uint uVar3;
  uint *in_a0;
  uint uVar5;
  
  func_0x800653d0(in_a0,&DAT_800e1158,0,0);
  cVar4 = func_0x8006568c((int)*(short *)((int)in_a0 + 0x2a),(int)*(short *)((int)in_a0 + 0x32));
  if (cVar4 == -1) {
    *(undefined2 *)(in_a0 + 0x98) = _DAT_800e115a;
    *(undefined2 *)((int)in_a0 + 0x262) = _DAT_800e1162;
  }
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
    }
    if (((*(ushort *)((int)in_a0 + 0x2b6) & 1) != 0) &&
       (cVar4 = *(char *)(in_a0 + 0xae), *(char *)(in_a0 + 0xae) = cVar4 + -1,
       (char)(cVar4 + -1) == -1)) {
      if (*(char *)((int)in_a0 + 0x2b9) != '\0') {
        *(char *)((int)in_a0 + 0x2b9) = *(char *)((int)in_a0 + 0x2b9) + -1;
      }
      *(undefined1 *)(in_a0 + 0xae) = 0xf;
      if (*(char *)((int)in_a0 + 0x2b9) == '\0') {
        *(ushort *)((int)in_a0 + 0x2b6) = *(ushort *)((int)in_a0 + 0x2b6) & 0xfffe;
      }
    }
    if (*(char *)((int)in_a0 + 0x2ba) != '\0') {
      *(char *)((int)in_a0 + 0x2ba) = *(char *)((int)in_a0 + 0x2ba) + -1;
    }
    if (*(char *)((int)in_a0 + 0x2ce) != '\0') {
      *(char *)((int)in_a0 + 0x2ce) = *(char *)((int)in_a0 + 0x2ce) + -1;
    }
    if (*(char *)((int)in_a0 + 0x2cf) != '\0') {
      *(char *)((int)in_a0 + 0x2cf) = *(char *)((int)in_a0 + 0x2cf) + -1;
    }
    if (*(char *)(in_a0 + 0xb6) != '\0') {
      *(char *)(in_a0 + 0xb6) = *(char *)(in_a0 + 0xb6) + -1;
    }
    if ((*(ushort *)((int)in_a0 + 0x1aa) & 1) != 0) {
      uVar5 = in_a0[0x82];
      *(short *)(uVar5 + 4) = (short)((int)(in_a0[0xb] * 0x17) / 100) + 0x8fc;
      *(short *)(uVar5 + 6) = (short)((int)(in_a0[0xb] * 0xd) / 100) + 0x514;
    }
    FUN_8016bf68();
    (*(code *)(&PTR_FUN_8016c350)[*(byte *)(in_a0 + 1)])();
    FUN_80167cc0();
    FUN_8016ab84();
    FUN_8016b8d4();
    if (((*(byte *)((int)in_a0 + 0x1e9) & 0x1f) == 0) &&
       ((*(ushort *)((int)in_a0 + 0x2b6) & 0x800) == 0)) {
      uVar5 = func_0x80033604();
      uVar3 = func_0x80033604();
      FUN_8016baa0(0,7 - (uVar5 & 0xff) % 0xe,7 - (uVar3 & 0xff) % 0xe);
      uVar5 = func_0x80033604();
      uVar3 = func_0x80033604();
      FUN_8016baa0(1,(int)((4 - (uVar5 & 7)) * 0x10000) >> 0x10,
                   (int)((4 - (uVar3 & 7)) * 0x10000) >> 0x10);
      uVar5 = func_0x80033604();
      uVar3 = func_0x80033604();
      FUN_8016baa0(2,7 - (uVar5 & 0xff) % 0xe,7 - (uVar3 & 0xff) % 0xe);
    }
    FUN_8016bac8();
    FUN_8016bac8();
    FUN_8016bac8();
    func_0x80033648();
    func_0x8004da40();
    in_a0[0x50] = *(uint *)(in_a0[0x8d] + 0x267c);
    uVar5 = *(uint *)(in_a0[0x8d] + 0x2684);
    *(undefined1 *)((int)in_a0 + 0xd) = 0xff;
    uVar2 = _DAT_800e13e8;
    in_a0[0x52] = uVar5;
    func_0x8004d3a0(uVar2);
    func_0x8004dcb8();
    uVar1 = *(ushort *)((int)in_a0 + 0x2b6);
    *(ushort *)((int)in_a0 + 0x2b6) = uVar1 & 0xffbf;
    if (((uVar1 & 0x1000) == 0) && (*(ushort *)((int)in_a0 + 0x136) < 0x578)) {
      *(ushort *)((int)in_a0 + 0x136) = *(ushort *)((int)in_a0 + 0x136) + 10;
      *(short *)(in_a0 + 0x4e) = *(short *)(in_a0 + 0x4e) + 10;
      *(short *)((int)in_a0 + 0x12e) = *(short *)((int)in_a0 + 0x12e) + 10;
      *(short *)(in_a0 + 0x4b) = *(short *)(in_a0 + 0x4b) + 10;
    }
    uVar5 = *in_a0;
    *in_a0 = uVar5 & 0xfffffbff;
    if (*(short *)((int)in_a0 + 0x25e) != 0) {
      *in_a0 = uVar5 & 0xfffffbff | 0x400;
    }
  }
  return;
}
