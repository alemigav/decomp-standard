/* FUN_80161d84
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80161d84  body 0x80161d84..0x80162083  size 768 B
 * body sha256 d779b0e8dbae42fc9683422e2c4262e7e2b1c12c76a538f248b13611f9bc03e8
 * provider record sha256 3be462e65455ce5c531f1ab4b8a702ed9fbcc82e3afff64e7be8a9d87b204c29
 * callees 5 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161d84(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar5 = 0;
  bVar1 = (&DAT_80163040)[*(ushort *)((int)param_1 + 0x1aa) & 0xf];
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  param_1[1] = (uint)bVar1 * 0x10000 + 0x1000000;
  puVar4 = param_1;
  do {
    puVar4[0xad] = 0;
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar5 < 0xc);
  *(undefined1 *)((int)param_1 + 0x1ed) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0xd;
  *(undefined2 *)((int)param_1 + 0x1f2) = 1;
  *param_1 = *param_1 | 0x4400002;
  func_0x800339dc(param_1 + 0x82,0,0xc801f4,0,param_1 + 10);
  param_1[0x94] = 0x800e1130;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xff38;
  *(undefined2 *)((int)param_1 + 0x136) = 100;
  *(undefined2 *)(param_1 + 0x4e) = 100;
  *(undefined2 *)((int)param_1 + 0x13a) = 200;
  *(undefined2 *)(param_1 + 0x4b) = 200;
  *(undefined2 *)((int)param_1 + 0x12e) = 200;
  *(undefined2 *)((int)param_1 + 0x28a) = 200;
  *(undefined1 *)(param_1 + 0x97) = 1;
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined1 *)((int)param_1 + 0x1a2) = 0;
  *(undefined1 *)((int)param_1 + 0x2b6) = 0;
  *(undefined1 *)((int)param_1 + 0x2b7) = 0xf;
  *(undefined1 *)(param_1 + 0xae) = 0;
  uVar5 = func_0x80033604();
  param_1[0x7a] = (uVar5 & 0xf) << 0x10;
  func_0x80089d54(param_1,param_2,param_3,0x80);
  uVar5 = *param_1;
  uVar3 = *(ushort *)((int)param_1 + 0x1aa);
  *param_1 = uVar5 | 0x400000;
  if (uVar3 == 0x2006) {
    uVar5 = func_0x80033604();
    uVar6 = 0xfffffc00;
LAB_80162034:
    FUN_80162084(param_1,uVar6,(uVar5 & 0xff) * 0x10 + 0x400,0);
    *(undefined2 *)(param_1 + 0x78) = 0;
    goto LAB_8016205c;
  }
  if (uVar3 < 0x2007) {
    if (uVar3 == 0x2004) {
      uVar5 = func_0x80033604();
      uVar6 = 0x400;
      goto LAB_80162034;
    }
    if (0x2004 < uVar3) {
      uVar5 = func_0x80033604();
      FUN_80162084(param_1,(uVar5 & 0xff) << 4,0,0xfffffc00);
      *(undefined2 *)(param_1 + 0x78) = 0;
      goto LAB_8016205c;
    }
    if (uVar3 == 0x2003) {
      uVar5 = func_0x80033604();
      FUN_80162084(param_1,(uVar5 & 0xff) << 4,0,0x400);
      *(undefined2 *)(param_1 + 0x78) = 0;
      goto LAB_8016205c;
    }
LAB_80162044:
    uVar3 = func_0x80033604();
    *(ushort *)((int)param_1 + 0x66) = (uVar3 & 0xff) << 4;
  }
  else {
    if (uVar3 == 0x6001) {
      *param_1 = uVar5 | 0x400400;
      *(undefined2 *)(param_1 + 0x1a) = 0;
      *(undefined2 *)(param_1 + 0x19) = 0;
      *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)(param_1 + 0x78);
      *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_1 + 0x79);
      goto LAB_80162044;
    }
    if (uVar3 < 0x6002) {
      if (uVar3 == 0x2008) {
        *(undefined1 *)(param_1 + 0xb0) = 1;
      }
      goto LAB_80162044;
    }
    if (uVar3 != 0x6002) goto LAB_80162044;
    *param_1 = uVar5 | 0x480400;
    iVar2 = func_0x80036ed8(param_1,0,0x3a,0);
    *(undefined *)((int)param_1 + 0x2be) = (&DAT_8016304c)[iVar2];
  }
  *(undefined2 *)(param_1 + 0x78) = 0;
LAB_8016205c:
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  return;
}
