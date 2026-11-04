/* thread1_entry
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006c0d4  body 0x8006c0d4..0x8006cb93  size 2564 B
 * body sha256 8d96b25cfa65daace10caad015ca1144a30d3e9ca85ee82617744de29eca3e68
 * provider record sha256 0d92f11f43d407f6539676d8623c715ecefb2f77fc79426d56004273fd348191
 * callees 32 direct (31 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8006c2ec) */
/* WARNING: Removing unreachable block (ram,0x8006c944) */
/* WARNING: Removing unreachable block (ram,0x8006c9b4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thread1_entry(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_38 [2];
  
  FUN_8006bda4();
  FUN_8008857c();
  FUN_800258d8(&DAT_80112868,&DAT_801128a8,&DAT_801128e8,&DAT_80112928);
  func_0x8000e920(0x80139f10,3,1);
  osRecvMesg(0x80139f10,local_38,1);
  osSendMesg(0x80139f10,0,0);
  osCreateMesgQueue(0x80139f30,0x8013a040,1);
  osCreateMesgQueue(0x80139f50,0x8013a044,1);
  osCreateMesgQueue(0x80139f70,0x8013a048,1);
  osCreateMesgQueue(0x80139f90,0x8013a04c,1);
  osCreateMesgQueue(0x8013a100,0x8013a118,1);
  osCreateMesgQueue(0x80139fb0,0x8013a050,1);
  DAT_80112d1c = DAT_80112d1c | 0x400;
  osCreateThread(&DAT_80112bf0,2,thread2_entry,0,&DAT_800bfca0,0x1e);
  osStartThread(&DAT_80112bf0);
  uVar3 = 0x80139f10;
  uVar4 = 0xf;
  func_0x8000cec0(0x80139ef0);
  _DAT_80139e60 = _DAT_80139e60 & 0xffffff7f;
  osCreateMesgQueue(&DAT_80112a24,0x8013a060,0x14);
  osCreateMesgQueue(0x80139fd0,0x8013a0b0,0x14);
  osCreateThread(&DAT_80112da0,3,FUN_8006baf4,0,&DAT_800c04a0,0x14,uVar3,uVar4);
  osStartThread(&DAT_80112da0);
  osCreateThread(&DAT_80112f50,4,&DAT_8006beb4,0,&DAT_800c24a0,0x1f);
  osCreateThread(&DAT_80113100,5,&DAT_8006beb4,0,&DAT_800c34a0,0x1f);
  osCreateThread(&DAT_801132b0,8,FUN_800880d0,0,&DAT_800c3ea0,0x32);
  osStartThread(&DAT_801132b0);
  DAT_80113478 = 1;
  DAT_8011347c = &DAT_80113480;
  DAT_80113480 = 4;
  DAT_80113484 = 0x80139f10;
switchD_8006c414_caseD_7:
switchD_8006c414_default:
  osRecvMesg(0x80139f10,local_38,1);
  switch(local_38[0]) {
  case 0:
    uVar3 = func_0x800072e0();
    FUN_800879a0(&DAT_80113478);
    goto LAB_8006c7ac;
  case 1:
    uVar3 = func_0x800072e0();
    if (DAT_8011277e == 5) {
      iVar1 = func_0x8000db20(&DAT_80112868 + (uint)DAT_8011277f * 0x40,1);
      if (iVar1 == 0) {
        DAT_8011277e = DAT_8011277f;
        (&DAT_80112968)[DAT_8011277f] = 6;
      }
      DAT_8011277f = 10;
    }
    FUN_8006b3dc(DAT_8011277e,1,2);
    switch(DAT_8011277e) {
    case 0:
      DAT_80112968 = 7;
      break;
    case 1:
      DAT_80112969 = 7;
      break;
    case 2:
      DAT_8011296a = 7;
      break;
    case 3:
      DAT_8011296b = 7;
      _DAT_80139e60 = _DAT_80139e60 | 4;
      break;
    case 4:
      if (DAT_8011277c == '\x05') {
        DAT_8011277c = '\x04';
      }
      osSendMesg(0x80139fd0,1,0);
      if ((~(_DAT_80139e60 & 0xfffffffb) & 2) == 0) {
        _DAT_80139e60 = _DAT_80139e60 & 0xfffffff9;
        DAT_8011296c = '\0';
      }
      else {
        DAT_8011296c = '\b';
        _DAT_80139e60 = _DAT_80139e60 & 0xfffffffb;
      }
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      break;
    case 0xb:
      DAT_8011277c = '\b';
      FUN_8009f834();
    default:
      goto LAB_8006c600;
    }
LAB_8006c600:
    DAT_8011277e = 10;
    break;
  case 2:
    uVar3 = func_0x800072e0();
    FUN_8006b3dc(DAT_8011277d,2,2);
    if (DAT_8011277d == 1) {
      if (DAT_8011277f == 1) {
        DAT_8011277f = 10;
      }
      DAT_80112969 = 2;
      do {
        iVar1 = osRecvMesg(0x80139f90,0,0);
      } while (iVar1 != -1);
      uVar4 = 0x80139f90;
LAB_8006c6e4:
      osSendMesg(uVar4,DAT_801127e0,0);
      FUN_8002687c();
    }
    else {
      if (DAT_8011277d < 2) {
        if (DAT_8011277d != 0) {
          DAT_8011277d = 10;
          break;
        }
        if (DAT_8011277f == 0) {
          DAT_8011277f = 10;
        }
        DAT_80112968 = 8;
        do {
          iVar1 = osRecvMesg(0x80139f70,0,0);
        } while (iVar1 != -1);
        uVar4 = 0x80139f70;
        goto LAB_8006c6e4;
      }
      if (DAT_8011277d == 2) {
        func_0x80006f00(&DAT_80112858);
        if (DAT_8011277f == 2) {
          DAT_8011277f = 10;
        }
        DAT_8011296a = 8;
        do {
          iVar1 = osRecvMesg(0x80139fb0,0,0);
        } while (iVar1 != -1);
        uVar4 = 0x80139fb0;
      }
      else {
        if (DAT_8011277d != 3) {
          DAT_8011277d = 10;
          break;
        }
        if (DAT_8011277f == 3) {
          DAT_8011277f = 10;
        }
        DAT_8011296b = 8;
        do {
          iVar1 = osRecvMesg(0x8013a100,0,0);
        } while (iVar1 != -1);
        uVar4 = 0x8013a100;
      }
      osSendMesg(uVar4,DAT_801127e0,0);
    }
    DAT_8011277d = 10;
    break;
  case 3:
    uVar3 = func_0x800072e0();
    DAT_80112a1c = DAT_80112a1c + 1;
    uVar2 = ((uint)(byte)(&DAT_80112974)[DAT_801127a8] * 0xbebc2) / 0x7f;
    if (0xbebc2 < uVar2) {
      uVar2 = 0xbebc2;
    }
    FUN_80088254(0,0,uVar2,0xbebc2 - uVar2,2);
    DAT_801127a8 = DAT_801127a8 ^ 1;
    func_0x8000dd70(0x80139ef0);
    func_0x8000cec0(0x80139ef0);
    _DAT_80139e60 = _DAT_80139e60 & 0xffffff7f;
    if ((DAT_80112a1c & 1) != 0) {
      func_0x8000dd70(0x80139e90);
      func_0x8000cec0(0x80139e90);
      _DAT_80139e60 = _DAT_80139e60 & 0xfffffff7;
      func_0x8000dd70(0x80139e70);
      func_0x8000cec0(0x80139e70);
      _DAT_80139e60 = _DAT_80139e60 & 0xfffffffe;
      if (DAT_8011296c == '\b') {
        DAT_8011296c = '\0';
      }
      else {
        _DAT_80139e60 = _DAT_80139e60 | 2;
      }
      if (DAT_80112784 == 0) {
        osSendMesg(&DAT_80112a24,0,0);
      }
      else {
        DAT_80112788 = DAT_80112788 + 1;
      }
    }
    osSendMesg(0x80139f10,0,0);
    if (DAT_801344c0 < 2) {
      FUN_8006b6b4();
      FUN_8006b8a0();
      do {
        iVar1 = osRecvMesg(0x80139f50,0,0);
      } while (iVar1 != -1);
      osSendMesg(0x80139f50,DAT_80112a1c,0);
      func_0x80007300(uVar3);
      FUN_8006bfc4();
      FUN_800268bc();
    }
    else if (DAT_801344c0 == 3) {
      FUN_8009f60c();
      FUN_8006b6b4();
      FUN_8006b8a0();
    }
    goto switchD_8006c414_default;
  case 4:
    func_0x80006778(&DAT_80113460);
    goto switchD_8006c414_default;
  case 5:
    uVar3 = func_0x800072e0();
    _DAT_80139e60 = _DAT_80139e60 | 1;
    break;
  case 6:
    uVar3 = func_0x800072e0();
    _DAT_80139e60 = _DAT_80139e60 | 8;
    break;
  case 7:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
    goto switchD_8006c414_caseD_7;
  case 8:
    uVar3 = func_0x800072e0();
    func_0x8000ec10(0x3f800000);
    func_0x8000eb40(0x3f800000);
    if (_DAT_80000300 == 2) {
      uVar4 = 0x80013450;
    }
    else {
      uVar4 = 0x80012b90;
    }
    func_0x8000e980(uVar4);
    func_0x8000e350(1);
    func_0x8000dcb0(&DAT_80112bf0);
    func_0x8000dcb0(&DAT_80112f50);
    func_0x8000dcb0(&DAT_80113100);
    func_0x8000dcb0(&DAT_80112da0);
    FUN_800b2010();
    func_0x80007300(uVar3);
    FUN_80088334(0);
    func_0x8000dcb0(&DAT_80112a40);
    goto switchD_8006c414_default;
  case 0xf:
    goto switchD_8006c414_caseD_f;
  default:
    goto switchD_8006c414_default;
  }
  FUN_8006b6b4();
  FUN_8006b8a0();
LAB_8006c7ac:
  func_0x80007300(uVar3);
  goto switchD_8006c414_default;
switchD_8006c414_caseD_f:
  DAT_80112a18 = 1;
  uVar3 = func_0x800072e0();
  _DAT_80139e60 = _DAT_80139e60 | 0x80;
  func_0x80007300(uVar3);
  goto switchD_8006c414_default;
}
