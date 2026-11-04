/* FUN_8015fde0
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015fde0  body 0x8015fde0..0x8016040f  size 1584 B
 * body sha256 62263cf98e74324b00fa2c2855daa7bcc70e3f8d6bcf96b6a35878e07380de13
 * provider record sha256 c6b616a9870d70838b1d0fc8e5a1593b11a4f32e1af866a8b5ac50c0792c8321
 * callees 19 direct (16 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015fde0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  DAT_80131780 = 3;
  DAT_800e923f = 0;
  func_0x800274e4(2,1);
  if ((int)_DAT_800e110c < 0) {
    DAT_800e10fa = '\x02';
  }
  else {
    DAT_800e10fa = '\0';
  }
  if ((_DAT_800e110c & 0x40000000) != 0) {
    DAT_800e10fa = DAT_800e10fa + '\x01';
  }
  if ((_DAT_800e10ec & 8) != 0) {
    _DAT_800e110c = _DAT_800e110c | 0x2000000;
    DAT_800e10fa = '\x04';
  }
  if ((_DAT_800e10ec & 0x2008) == 0) {
    overlay_slot_reader(1,5);
    func_0x8004cd88(1);
  }
  if ((_DAT_800e10ec & 0x20000) == 0) {
    if ((_DAT_800e10ec & 0x2000) == 0) {
      DAT_800e1138 = DAT_800e8b3a;
      _DAT_800e1158 = (int)_DAT_800e8b52;
      _DAT_800e115c = (int)_DAT_800e8b54;
      _DAT_800e1160 = (int)_DAT_800e8b56;
      _DAT_800e1196 = _DAT_800e900c;
      DAT_800e12d2 = -(char)((int)_DAT_800e8b54 / 0x708);
      _DAT_800e110c = _DAT_800e110c | 0x40;
    }
    else {
      _DAT_800e10ec = _DAT_800e10ec & 0xffffffdf;
      _DAT_800e110c = _DAT_800e110c & 0xfbffffff | 0x40;
      _DAT_800e8ca8 = (ushort)DAT_801317c8;
      _DAT_800e8caa = (ushort)DAT_801317c9;
      _DAT_800e8cac = (ushort)DAT_801317ca;
      DAT_800e8b48 = DAT_801317cb;
      DAT_8012bfa2 = DAT_801317cb;
      DAT_800e8b49 = DAT_801317cc;
      DAT_8012bfa0 = DAT_801317cc;
      DAT_800e1138 = DAT_801317ce;
      _DAT_800e1158 = (int)_DAT_801317fe;
      _DAT_800e115c = (int)_DAT_80131800;
      _DAT_800e1160 = (int)_DAT_80131802;
      _DAT_800e1196 = _DAT_80131804;
      DAT_800e12d2 = -(char)((int)_DAT_80131800 / 0x708);
      DAT_800e8b38 = 8;
      puVar1 = (undefined4 *)&DAT_800e8ec8;
      puVar2 = (undefined4 *)&DAT_801317d0;
      do {
        puVar5 = puVar2;
        puVar4 = puVar1;
        uVar7 = puVar5[1];
        uVar8 = puVar5[2];
        uVar6 = puVar5[3];
        *puVar4 = *puVar5;
        puVar4[1] = uVar7;
        puVar4[2] = uVar8;
        puVar4[3] = uVar6;
        puVar1 = puVar4 + 4;
        puVar2 = puVar5 + 4;
      } while (puVar5 + 4 != (undefined4 *)&DAT_801317f0);
      uVar6 = puVar5[5];
      uVar7 = puVar5[6];
      puVar4[4] = _DAT_801317f0;
      puVar4[5] = uVar6;
      puVar4[6] = uVar7;
      _DAT_800e8b4a = 200;
      DAT_80131f0e = DAT_800e8b3e;
      DAT_800e8b3e = DAT_801317cd;
      DAT_800e9243 = 0;
    }
    _DAT_800e8cae = 0xff;
    _DAT_800e1322 = _DAT_800e8b4a;
  }
  else {
    uVar3 = _DAT_800e110c | 0x40;
    if ((_DAT_800e10ec & 0x20) != 0) {
      uVar3 = _DAT_800e110c | 0x4000040;
    }
    _DAT_800e110c = uVar3;
    FUN_8015bac8();
    if ((_DAT_800e10ec & 8) == 0) {
      if ((_DAT_800e110c & 0x40000000) == 0) {
        _DAT_800e8caa = 0;
        _DAT_800e12e4 = 0x4972;
        _DAT_800e1164 = 0x4972;
        _DAT_800e1158 = 0x4972;
        _DAT_800e12e6 = 0xf3a4;
        _DAT_800e1168 = 0xf3a4;
        _DAT_800e1160 = -0xc5c;
        _DAT_800e1196 = 0x800;
      }
      else {
        _DAT_800e8caa = 4;
        _DAT_800e1164 = 0xba00;
        _DAT_800e1158 = -0x4600;
        _DAT_800e12e4 = 0xab26;
        _DAT_800e1168 = 0xab26;
        _DAT_800e1160 = -0x54da;
        _DAT_800e1196 = 400;
      }
      _DAT_800e8ca8 = 0;
      _DAT_800e8cac = 0;
      _DAT_800e9010 = 200;
      DAT_800e900f = 0;
      DAT_800e1138 = (int)_DAT_800e110c < 0;
      _DAT_800e8b4a = 200;
      _DAT_800e1322 = 200;
    }
    else {
      _DAT_800e8ca8 = 2;
      _DAT_800e8caa = 4;
      _DAT_800e12e4 = 0xe301;
      _DAT_800e1164 = 0xe301;
      _DAT_800e1158 = -0x1cff;
      _DAT_800e12e6 = 0xa054;
      _DAT_800e1168 = 0xa054;
      _DAT_800e1160 = -0x5fac;
      _DAT_800e1196 = 0x800;
      _DAT_800e8cac = 3;
      if ((_DAT_800e10ec & 1) == 0) {
        DAT_800e1138 = 0xc;
        _DAT_800e1322 = 200;
      }
      else {
        DAT_800e1138 = 0xd;
        _DAT_800e1322 = 400;
      }
    }
    _DAT_800e138e = 0;
    DAT_800e12d2 = '\0';
    _DAT_800e115c = 0;
    _DAT_800e13e4 = 0;
    DAT_800e13e6 = 0;
    DAT_80160c18 = 0;
    DAT_800e8b3e = DAT_800e923e;
    func_0x8008b2e4();
  }
  func_0x8008b548();
  switch(DAT_800e10fa) {
  case '\0':
  case '\x01':
    uVar6 = 0;
    break;
  case '\x02':
  case '\x03':
    uVar6 = 1;
    break;
  case '\x04':
    uVar6 = 0xc;
    if ((_DAT_800e10ec & 1) != 0) {
      uVar6 = 0xd;
    }
    break;
  default:
    goto switchD_801602e4_default;
  }
  func_0x8007608c(uVar6,0);
switchD_801602e4_default:
  func_0x80075fc0();
  func_0x80037380();
  func_0x800324a8();
  func_0x80064ff0();
  _DAT_800e13e8 = &DAT_800e1130;
  _DAT_800e1130 = 1;
  _DAT_800df934 = _DAT_800df930;
  func_0x80055574();
  func_0x8007a754();
  func_0x800337c4();
  func_0x8006d0b0();
  func_0x800635b0();
  _DAT_800e10ec = _DAT_800e10ec | 0x40000000;
  _DAT_800dfbe4 = func_0x8006bb0c(0xffffffff);
  DAT_800e9182 = 2;
  func_0x800274e4(0,0);
  DAT_800e9183 = 1;
  func_0x80083c14((int)(short)_DAT_800e8cac);
  func_0x80083afc(1);
  return;
}
