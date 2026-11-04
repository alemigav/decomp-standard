/* FUN_8016edb4
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016edb4  body 0x8016edb4..0x8016fb53  size 128 B
 * body sha256 347876ae2f953dab44e9e4a65fb7abc3d64e6bc59df53e0854f164be427f6615
 * provider record sha256 8b02c252b0cee9e3172050cdd3ce47616a399f5755a5e70838dde0f2093079c3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016edb4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 in_a3;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined2 auStack_20 [4];
  
  switch(DAT_80171ddb) {
  case 0:
    if (DAT_80119e70 != '\0') goto LAB_8016fb2c;
    if ((_DAT_800e110c & 0x40000000) != 0) {
      func_0x8009f320(0xe);
    }
    auStack_20[0] = 0x26ff;
    _DAT_80119ea0 = auStack_20;
    DAT_80119ee5 = 0;
    _DAT_80119ee8 = 100;
    _DAT_80119eea = 100;
    func_0x80076c84();
    func_0x800777d8(0x1000000);
    DAT_80171ddb = 1;
    goto LAB_8016fa1c;
  case 1:
    if (DAT_80171de8 != 300) goto LAB_8016fb2c;
    FUN_80171540();
    DAT_80171ddb = 3;
    goto LAB_8016f974;
  case 3:
    if ((_DAT_800e10ec & 0x200) != 0) goto LAB_8016fb2c;
    if ((_DAT_800e110c & 0x40000000) == 0) {
      DAT_80171df4 = DAT_80171df4 | 0x800;
      func_0x80077430(0xb4,0x18);
    }
    DAT_80171ddb = 4;
    goto LAB_8016fa1c;
  case 4:
    if (DAT_80119e70 != '\0') goto LAB_8016fb2c;
    if ((_DAT_800e110c & 0x40000000) == 0) {
      auStack_20[0] = 0xffff;
      _DAT_80119ea0 = auStack_20;
      DAT_80119ee5 = 0;
      _DAT_80119ee8 = 100;
      _DAT_80119eea = 100;
      func_0x80076c84();
    }
    FUN_80171240((int)_DAT_800e110c < 0);
    FUN_80171294(0,0,1,0);
    DAT_80171df4 = DAT_80171df4 | 0x800;
    FUN_8016ebd0();
    auStack_20[0] = 0x26ff;
    _DAT_80119ea0 = auStack_20;
    DAT_80119ee5 = 0;
    _DAT_80119ee8 = 100;
    _DAT_80119eea = 100;
    func_0x80076c84();
    func_0x800777d8(0x1000000);
    DAT_80171ddb = 5;
    DAT_80171de8 = 0;
    DAT_80171dd8 = '\0';
    break;
  case 5:
    if ((_DAT_800df90c & 0x800) != 0) {
      if (DAT_80171de8 < 300) {
        if (DAT_80171dd8 == '\0') {
          DAT_80171de8 = 0x1e0;
        }
      }
      else {
        if (DAT_80171dd8 == '\0') {
          DAT_80171de8 = 0x1e0;
        }
        if (DAT_80171dd8 == '\x01') {
          DAT_80171de8 = 0x4b1;
        }
      }
    }
    if ((DAT_80171de8 == 0x1e0) && (DAT_80171dd8 == '\0')) {
      (&DAT_80171aac)[(DAT_80171ddc + 4) * 0xc] = 5;
      if ((_DAT_800e110c & 0x40000000) == 0) {
        if ((int)_DAT_800e110c < 0) {
          DAT_80171b24 = 5;
        }
        else {
          DAT_80171b18 = 5;
        }
      }
      else if ((int)_DAT_800e110c < 0) {
        DAT_80171b3c = 5;
      }
      else {
        DAT_80171b30 = 5;
      }
      FUN_801700ac(0x3e000,5,0,in_a3,0x4b0);
      DAT_80171df0 = 0x10101000;
      DAT_80171dd8 = '\x01';
      DAT_80171de8 = 0;
    }
    if (DAT_80171de8 < 0x4b1) goto LAB_8016fb2c;
    if ((DAT_80171df4 & 0x80) == 0) {
      func_0x80077430(0xb4,0x18);
      DAT_80171ddb = 7;
      DAT_80171df4 = DAT_80171df4 | 0x2008;
    }
    else {
      DAT_80171dec = 0x1bc0000;
      DAT_80171ddb = 6;
      DAT_80171df4 = DAT_80171df4 | 0x3000;
    }
    FUN_8016ecb8();
    goto LAB_8016fa1c;
  case 6:
    if ((300 < DAT_80171de8) && ((_DAT_800df90c & 0x800) != 0)) {
      DAT_80171de8 = 0x385;
    }
    if (DAT_80171de8 < 0x385) goto LAB_8016fb2c;
    func_0x80077430(0xb4,0x18);
    DAT_80171df4 = DAT_80171df4 | 0x2008;
    FUN_8016ecb8();
    DAT_80171ddb = 7;
    goto LAB_8016f974;
  case 7:
    if (DAT_80119e70 != '\0') goto LAB_8016fb2c;
    if ((_DAT_800e110c & 0x40000000) == 0) {
      _DAT_800e110c = _DAT_800e110c | 0x40000000;
    }
    else {
      _DAT_800e110c = _DAT_800e110c & 0xbfffffff;
      uVar4 = func_0x8009bea0(_DAT_8010b6f8);
      func_0x8009bec8(_DAT_8010b6f8,uVar4 | 1);
    }
    if ((int)_DAT_800e110c < 0) {
      _DAT_800e110c = _DAT_800e110c & 0x7fffffff;
    }
    else {
      _DAT_800e110c = _DAT_800e110c | 0x80000000;
    }
    FUN_801708a4();
    _DAT_800e10ec = _DAT_800e10ec & 0xfffbffff;
    overlay_slot_reader(1,2);
    func_0x8004cd88(1);
    if ((_DAT_800e110c & 0x40000000) == 0) {
      _DAT_800e110c = _DAT_800e110c | 0x40000000;
    }
    else {
      _DAT_800e110c = _DAT_800e110c & 0xbfffffff;
    }
    if ((int)_DAT_800e110c < 0) {
      _DAT_800e110c = _DAT_800e110c & 0x7fffffff;
    }
    else {
      _DAT_800e110c = _DAT_800e110c | 0x80000000;
    }
    if ((_DAT_800e110c & 0x40000000) == 0) goto LAB_8016fb20;
    auStack_20[0] = 0xffff;
    DAT_80119ee5 = 0;
    _DAT_80119ee8 = 100;
    _DAT_80119eea = 100;
    _DAT_80119ea0 = auStack_20;
    func_0x80076c84();
    auStack_20[0] = 0xff33;
    DAT_80119eed = 0;
    _DAT_80119ef0 = 100;
    _DAT_80119ef2 = 100;
    DAT_80119ef5 = 0;
    _DAT_80119ef8 = 100;
    _DAT_80119efa = 100;
    _DAT_80119ea0 = auStack_20;
    func_0x80076c84();
    func_0x80076fd0();
    DAT_80171ddb = 8;
    goto LAB_8016fa1c;
  case 8:
    if ((DAT_80171df4 & 0x100) == 0) {
      DAT_80171ddb = 0xb;
    }
    else {
      FUN_80171240(2);
      FUN_80171294(0,0,1,0);
      DAT_80171df4 = DAT_80171df4 | 0x800;
      FUN_8016ebd0();
      func_0x800777d8(0x11000000);
      DAT_80171ddb = 9;
    }
    goto LAB_8016f880;
  case 9:
    if ((((_DAT_800df90c & 0x800) != 0) && (0xb4 < DAT_80171de8)) && (DAT_80171dd8 == '\x01')) {
      DAT_80171de8 = 0x155;
    }
    if ((DAT_80171de8 == 0x28) && (DAT_80171dd8 == '\0')) {
      FUN_801700ac(0x2000000,1,0,in_a3,0x4b0);
      DAT_80171dd8 = '\x01';
    }
    if (DAT_80171de8 < 0x155) goto LAB_8016fb2c;
    FUN_801700ac(0x2000000,0,0);
    DAT_80171df4 = DAT_80171df4 | 0x2008;
    FUN_8016ecb8();
    DAT_80171ddb = 10;
    goto LAB_8016f974;
  case 10:
    if (DAT_80171de8 != 0x3c) goto LAB_8016fb2c;
    puVar1 = &DAT_80171e80;
    puVar2 = (undefined4 *)&DAT_800e8b30;
    do {
      puVar5 = puVar2;
      puVar3 = puVar1;
      uVar6 = puVar3[1];
      uVar7 = puVar3[2];
      uVar8 = puVar3[3];
      *puVar5 = *puVar3;
      puVar5[1] = uVar6;
      puVar5[2] = uVar7;
      puVar5[3] = uVar8;
      puVar1 = puVar3 + 4;
      puVar2 = puVar5 + 4;
    } while (puVar3 + 4 != (undefined4 *)&UNK_80172360);
    uVar6 = puVar3[5];
    uVar7 = puVar3[6];
    puVar5[4] = 0;
    puVar5[5] = uVar6;
    puVar5[6] = uVar7;
    _DAT_800e10ec = _DAT_800e10ec | 8;
    FUN_801708a4();
    _DAT_800e10ec = _DAT_800e10ec & 0xfffbffff;
    overlay_slot_reader(1,2);
    func_0x8004cd88(1);
    DAT_80171ddb = 0xb;
    uVar4 = 0xfffffff7;
    goto LAB_8016f824;
  case 0xb:
    if ((DAT_80171df4 & 0x200) == 0) {
      DAT_80171ddb = 0xe;
    }
    else {
      FUN_80171240(4);
      FUN_80171294(0,0,1,0);
      DAT_80171df4 = DAT_80171df4 | 0x800;
      FUN_8016ebd0();
      func_0x800777d8(0x11000000);
      DAT_80171ddb = 0xc;
    }
LAB_8016f880:
    DAT_80171de8 = 0;
    DAT_80171dd8 = '\x01';
    break;
  case 0xc:
    if ((((_DAT_800df90c & 0x800) != 0) && (0xb4 < DAT_80171de8)) && (DAT_80171dd8 == '\x01')) {
      DAT_80171de8 = 0x155;
    }
    if ((DAT_80171de8 == 0x28) && (DAT_80171dd8 == '\0')) {
      FUN_801700ac(0x4000000,1,0,in_a3,0x4b0);
      DAT_80171dd8 = '\x01';
      DAT_80171de8 = 0;
    }
    if (DAT_80171de8 < 0x155) goto LAB_8016fb2c;
    FUN_801700ac(0x4000000,0,0);
    DAT_80171df4 = DAT_80171df4 | 0x2008;
    FUN_8016ecb8();
    DAT_80171ddb = 0xd;
    goto LAB_8016f974;
  case 0xd:
    if (DAT_80171de8 != 0x3c) goto LAB_8016fb2c;
    puVar1 = &DAT_80171e80;
    puVar2 = (undefined4 *)&DAT_800e8b30;
    do {
      puVar5 = puVar2;
      puVar3 = puVar1;
      uVar6 = puVar3[1];
      uVar7 = puVar3[2];
      uVar8 = puVar3[3];
      *puVar5 = *puVar3;
      puVar5[1] = uVar6;
      puVar5[2] = uVar7;
      puVar5[3] = uVar8;
      puVar1 = puVar3 + 4;
      puVar2 = puVar5 + 4;
    } while (puVar3 + 4 != (undefined4 *)&UNK_80172360);
    uVar6 = puVar3[5];
    uVar7 = puVar3[6];
    puVar5[4] = 0;
    puVar5[5] = uVar6;
    puVar5[6] = uVar7;
    _DAT_800e10ec = _DAT_800e10ec | 9;
    FUN_801708a4();
    _DAT_800e10ec = _DAT_800e10ec & 0xfffbffff;
    overlay_slot_reader(1,2);
    func_0x8004cd88(1);
    DAT_80171ddb = 0xe;
    _DAT_800e10ec = _DAT_800e10ec & 0xfffffff7;
    uVar4 = 0xfffffffe;
LAB_8016f824:
    DAT_80171de8 = 0;
    _DAT_800e10ec = _DAT_800e10ec & uVar4;
    break;
  case 0xe:
    if ((DAT_80171df4 & 0x400) != 0) {
      FUN_80171240(3);
      FUN_80171294(0,0,1,0);
      DAT_80171df4 = DAT_80171df4 | 0x800;
      FUN_8016ebd0();
      func_0x800777d8(0x21000000);
      DAT_80171ddb = 0xf;
      goto LAB_8016f880;
    }
    goto LAB_8016fb20;
  case 0xf:
    if ((DAT_80171de8 == 0x28) && (DAT_80171dd8 == '\0')) {
      FUN_801700ac(0x8000000,5,0,in_a3,0x4b0);
    }
    if (DAT_80171de8 == 0x3c) {
      FUN_801700ac(0x20000000,1,0);
    }
    if (DAT_80171de8 == 0xf0) {
      FUN_801700ac(0x28000000,0,0);
      FUN_801700ac(0x10000000,5,0);
    }
    if (DAT_80171de8 == 0x104) {
      FUN_801700ac(0x40000000,1,0);
    }
    if (DAT_80171de8 < 0x1b9) goto LAB_8016fb2c;
    FUN_801700ac(0x40000000,0,0);
    DAT_80171df4 = DAT_80171df4 | 0x2008;
    FUN_8016ecb8();
    DAT_80171ddb = 0x10;
LAB_8016f974:
    DAT_80171de8 = 0;
    break;
  case 0x10:
    if (DAT_80171de8 != 0x1e) goto LAB_8016fb2c;
    FUN_801700ac(0x50000000,0,0,in_a3,0x4b0);
    goto LAB_8016fb20;
  case 0x11:
    if (DAT_80119e70 != '\0') goto LAB_8016fb2c;
    auStack_20[0] = 0x30ff;
    _DAT_80119ea0 = auStack_20;
    DAT_80119ee5 = 0;
    _DAT_80119ee8 = 100;
    _DAT_80119eea = 100;
    func_0x80076c84();
    func_0x800777d8(0x1000000);
    FUN_8016ebd0();
    DAT_80171df0 = 0x10101000;
    DAT_80171ddb = 0x12;
LAB_8016fa1c:
    DAT_80171de8 = 0;
    break;
  case 0x12:
    if (DAT_80171de8 == 0xb4) {
      FUN_801700ac(1,5,0,in_a3,0x4b0);
    }
    if (DAT_80171de8 == 200) {
      FUN_801700ac(4,1,0);
    }
    if (DAT_80171de8 == 500) {
      FUN_801700ac(4,0,0);
      DAT_80171df4 = DAT_80171df4 | 0x2008;
      FUN_8016ecb8();
    }
    if (DAT_80171de8 == 0x280) {
      FUN_801700ac(2,5,0);
    }
    if (DAT_80171de8 == 0x294) {
      FUN_801700ac(8,1,0);
    }
    if (DAT_80171de8 == 0x424) {
      FUN_801700ac(8,0,0);
      DAT_80171df4 = DAT_80171df4 | 0x2008;
      FUN_8016ecb8();
      func_0x80077430(0xb4,0x18);
    }
    if (DAT_80171de8 != 0x4b0) goto LAB_8016fb2c;
LAB_8016fb20:
    FUN_8016eb74();
  }
LAB_8016fb2c:
  DAT_80171de8 = DAT_80171de8 + 1;
  return;
}
