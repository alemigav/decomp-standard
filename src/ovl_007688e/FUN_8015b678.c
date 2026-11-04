/* FUN_8015b678
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015b678  body 0x8015b678..0x8015ba5f  size 556 B
 * body sha256 ea6e653d769dd71ab0c2823b5ae83a75ee0d515457787ed578e216650e1c6f71
 * provider record sha256 804770dfc069c797e5b8bfce21ccdf6ce7cec1ab885e3344b653c732d07db3f0
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015b678(void)

{
  int iVar1;
  
  DAT_80160c2c = DAT_80160c2c + DAT_80160c2e;
  func_0x800274f8(0x200,0,7,1);
  func_0x800275c0(0,(int)DAT_80160c2c,0,0);
  iVar1 = func_0x8002767c(0);
  if (iVar1 != 0) {
    DAT_80160c2e = 0;
    DAT_80160c2c = -1;
  }
  DAT_80160c2a = DAT_80160c2a + 1;
  if (DAT_80160c2a < 0x708) {
    if (_DAT_800df90e != 0) {
      DAT_80160c2a = 0;
    }
    switch(DAT_80160c1e) {
    case 0:
      FUN_8015bc3c();
      break;
    case 1:
      FUN_8015be7c();
      break;
    case 2:
      FUN_8015d268();
      break;
    case 3:
      FUN_8015c23c();
      break;
    case 4:
      FUN_8015cae0();
      break;
    case 5:
      FUN_8015ce7c();
      break;
    case 6:
      DAT_80160c1d = DAT_80160c21 + '\x02';
      if (DAT_80160c1d == '\x04') {
        func_0x80077adc(0x4060000,0);
        func_0x800274f8(0x200,0x1800,7,1);
        func_0x800275c0(0,0x200,0x1085,0);
        while (iVar1 = func_0x8002767c(0), iVar1 == 0) {
          FUN_8015fc08();
          FUN_8015ba60();
          func_0x8004cd88(1);
        }
      }
      else {
        func_0x80077adc(0x4000000,0);
        func_0x800274f8(0x100,0xfffff800,7,1);
        while (iVar1 = func_0x8002767c(0), iVar1 == 0) {
          FUN_8015ba60();
          FUN_8015fc08();
          func_0x8004cd88(1);
        }
        func_0x800274f8(0x200,0x800,7,1);
        func_0x800275c0(0,0x200,0x1085,0);
        while (iVar1 = func_0x8002767c(0), iVar1 == 0) {
          FUN_8015ba60(0x200);
          FUN_8015fc08();
          func_0x8004cd88(1);
        }
      }
      func_0x800274f8(0x200,0,7,1);
      func_0x800275c0(0,0x7fff,0xffff,0);
      func_0x8004cd88(1);
    case 7:
      FUN_8015c60c();
    }
  }
  else {
    if (DAT_80160c2a == 0x708) {
      DAT_80160c2e = 0x100;
      DAT_80160c2c = 0;
    }
    else {
      iVar1 = func_0x8002767c(0);
      if (iVar1 != 0) {
        func_0x800274f8(0x200,0,7,1);
        func_0x800275c0(0,0x7fff,0,0);
        _DAT_800e10ec = _DAT_800e10ec | 0x2000;
        if ((DAT_800e10fb & 1) == 0) {
          _DAT_800e110c = _DAT_800e110c & 0x7fffffff;
        }
        else {
          _DAT_800e110c = _DAT_800e110c | 0x80000000;
        }
        func_0x80004cfc(*(undefined2 *)(&DAT_80160b64 + (uint)DAT_800e10fb * 2),&DAT_801317c8,
                        0x80000000,"PDEM_DAT");
        DAT_800e10fb = DAT_800e10fb + 1;
        if (5 < DAT_800e10fb) {
          DAT_800e10fb = 0;
        }
        DAT_80160c1d = '\x03';
      }
    }
    if ((_DAT_800df90e & 0x9ff) != 0) {
      func_0x80077adc(0x4050000,0);
      DAT_80160c2a = 0;
      DAT_80160c2e = -0x1000;
      DAT_80160c1f = 0;
    }
  }
  FUN_8015fbb8();
  return;
}
