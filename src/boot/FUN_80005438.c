/* FUN_80005438
 * image   boot (boot), base 0x80000480
 * address 0x80005438  body 0x80005438..0x80005e83  size 2636 B
 * body sha256 233bb5bc98d04128d659c668c315b098768c26715bb8f338ec62224606a37791
 * provider record sha256 a50dab93dd7aa9c5e9df23f038bee67796df3422f3137186226863ab14b2115e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_80005438(undefined2 param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint unaff_s0;
  
  FUN_800051b8(param_1);
  FUN_800053f4(_DAT_800128ac);
  uVar6 = _DAT_800128a0 >> 8;
  uVar2 = _DAT_800128a4 - 8;
  uVar7 = _DAT_800128a0 & 0xff;
  _DAT_800128a0 = uVar6;
  if ((int)uVar2 < 0x10) {
    uVar1 = *_DAT_8001289c;
    _DAT_8001289c = _DAT_8001289c + 1;
    _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar2 & 0x1f);
    uVar2 = _DAT_800128a4 + 8;
  }
  _DAT_800128a4 = uVar2;
  puVar3 = param_2;
  while (uVar7 = uVar7 - 1, uVar7 != 0xffffffff) {
    uVar6 = _DAT_800128a0 >> 9;
    uVar2 = _DAT_800128a4 - 9;
    uVar9 = _DAT_800128a0 & 0x1ff;
    _DAT_800128a0 = uVar6;
    if ((int)uVar2 < 0x10) {
      uVar1 = *_DAT_8001289c;
      _DAT_8001289c = _DAT_8001289c + 1;
      _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar2 & 0x1f);
      uVar2 = _DAT_800128a4 + 7;
    }
    _DAT_800128a4 = uVar2;
    uVar6 = _DAT_800128a0 >> 0xf;
    uVar2 = _DAT_800128a4 - 0xf;
    uVar5 = _DAT_800128a0 & 0x7fff;
    _DAT_800128a0 = uVar6;
    if ((int)uVar2 < 0x10) {
      uVar1 = *_DAT_8001289c;
      _DAT_8001289c = _DAT_8001289c + 1;
      _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar2 & 0x1f);
      uVar2 = _DAT_800128a4 + 1;
    }
    _DAT_800128a4 = uVar2;
    *puVar3 = uVar9 | uVar5 << 0x10;
    puVar3 = puVar3 + 1;
  }
  uVar7 = _DAT_800128a0 >> 0xc;
  uVar6 = _DAT_800128a4 - 0xc;
  uVar2 = _DAT_800128a0 & 0xfff;
  _DAT_800128a0 = uVar7;
  if ((int)uVar6 < 0x10) {
    uVar1 = *_DAT_8001289c;
    _DAT_8001289c = _DAT_8001289c + 1;
    _DAT_800128a0 = uVar7 | (uint)uVar1 << (uVar6 & 0x1f);
    uVar6 = _DAT_800128a4 + 4;
  }
  _DAT_800128a4 = uVar6;
  *puVar3 = uVar2;
  puVar4 = puVar3 + 1;
  uVar2 = uVar2 << 1;
  do {
    uVar6 = _DAT_800128a0 >> 1;
    if ((_DAT_800128a0 & 1) == 0) {
      uVar6 = _DAT_800128a0 >> 2;
      if ((_DAT_800128a0 & 2) == 0) {
        uVar6 = _DAT_800128a0 >> 3;
        if ((_DAT_800128a0 & 4) == 0) {
          uVar6 = _DAT_800128a0 >> 0xc;
          if ((_DAT_800128a0 & 8) == 0) {
            uVar6 = _DAT_800128a0 >> 0x10;
            if ((_DAT_800128a0 & 0x10) == 0) {
              uVar2 = _DAT_800128a4 - 0x10;
              _DAT_800128a0 = uVar6;
              if ((int)uVar2 < 0x10) {
                uVar1 = *_DAT_8001289c;
                _DAT_8001289c = _DAT_8001289c + 1;
                _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar2 & 0x1f);
                uVar2 = _DAT_800128a4;
              }
              do {
                _DAT_800128a4 = uVar2;
                uVar2 = _DAT_800128a0 >> 1;
                if ((_DAT_800128a0 & 1) == 0) {
                  uVar2 = _DAT_800128a0 >> 10;
                  if ((_DAT_800128a0 & 2) == 0) {
                    _DAT_800128a0 = _DAT_800128a0 >> 0x10;
                    uVar2 = _DAT_800128a4 - 0x10;
                    if ((int)uVar2 < 0x10) {
                      uVar1 = *_DAT_8001289c;
                      _DAT_8001289c = _DAT_8001289c + 1;
                      _DAT_800128a0 = _DAT_800128a0 | (uint)uVar1 << (uVar2 & 0x1f);
                      uVar2 = _DAT_800128a4;
                    }
                    _DAT_800128a4 = uVar2;
                    *puVar4 = (int)puVar4 - (int)param_2;
                    if (_DAT_800128ac < puVar4 + 1) {
                      trap(0);
                    }
                    return puVar4 + 1;
                  }
                  uVar6 = _DAT_800128a0 & 0x3ff;
                  uVar7 = _DAT_800128a4 - 10;
                  _DAT_800128a0 = uVar2;
                  if ((int)uVar7 < 0x10) {
                    uVar1 = *_DAT_8001289c;
                    _DAT_8001289c = _DAT_8001289c + 1;
                    _DAT_800128a0 = uVar2 | (uint)uVar1 << (uVar7 & 0x1f);
                    uVar7 = _DAT_800128a4 + 6;
                  }
                  _DAT_800128a4 = uVar7;
                  uVar6 = uVar6 >> 2;
                }
                else {
                  uVar6 = _DAT_800128a4 - 1;
                  _DAT_800128a0 = uVar2;
                  if ((int)uVar6 < 0x10) {
                    uVar1 = *_DAT_8001289c;
                    _DAT_8001289c = _DAT_8001289c + 1;
                    _DAT_800128a0 = uVar2 | (uint)uVar1 << (uVar6 & 0x1f);
                    uVar6 = _DAT_800128a4 + 0xf;
                  }
                  _DAT_800128a4 = uVar6;
                  uVar6 = 1;
                }
                uVar2 = _DAT_800128a0 >> 5;
                if ((_DAT_800128a0 & 1) == 0) {
                  uVar2 = _DAT_800128a0 >> 8;
                  if ((_DAT_800128a0 & 2) == 0) {
                    uVar2 = _DAT_800128a0 >> 0xd;
                    if ((_DAT_800128a0 & 4) != 0) {
                      uVar9 = _DAT_800128a0 & 0x1fff;
                      uVar7 = _DAT_800128a4 - 0xd;
                      _DAT_800128a0 = uVar2;
                      if ((int)uVar7 < 0x10) {
                        uVar1 = *_DAT_8001289c;
                        _DAT_8001289c = _DAT_8001289c + 1;
                        _DAT_800128a0 = uVar2 | (uint)uVar1 << (uVar7 & 0x1f);
                        uVar7 = _DAT_800128a4 + 3;
                      }
                      _DAT_800128a4 = uVar7;
                      unaff_s0 = (uVar9 >> 3) + 0x50;
                    }
                  }
                  else {
                    uVar9 = _DAT_800128a0 & 0xff;
                    uVar7 = _DAT_800128a4 - 8;
                    _DAT_800128a0 = uVar2;
                    if ((int)uVar7 < 0x10) {
                      uVar1 = *_DAT_8001289c;
                      _DAT_8001289c = _DAT_8001289c + 1;
                      _DAT_800128a0 = uVar2 | (uint)uVar1 << (uVar7 & 0x1f);
                      uVar7 = _DAT_800128a4 + 8;
                    }
                    _DAT_800128a4 = uVar7;
                    unaff_s0 = (uVar9 >> 2) + 0x10;
                  }
                }
                else {
                  uVar9 = _DAT_800128a0 & 0x1f;
                  uVar7 = _DAT_800128a4 - 5;
                  _DAT_800128a0 = uVar2;
                  if ((int)uVar7 < 0x10) {
                    uVar1 = *_DAT_8001289c;
                    _DAT_8001289c = _DAT_8001289c + 1;
                    _DAT_800128a0 = uVar2 | (uint)uVar1 << (uVar7 & 0x1f);
                    uVar7 = _DAT_800128a4 + 0xb;
                  }
                  _DAT_800128a4 = uVar7;
                  unaff_s0 = uVar9 >> 1;
                }
                uVar2 = _DAT_800128a0;
                _DAT_800128a0 = _DAT_800128a0 >> 3;
                uVar7 = _DAT_800128a4 - 3;
                if ((int)uVar7 < 0x10) {
                  uVar1 = *_DAT_8001289c;
                  _DAT_8001289c = _DAT_8001289c + 1;
                  _DAT_800128a0 = _DAT_800128a0 | (uint)uVar1 << (uVar7 & 0x1f);
                  uVar7 = _DAT_800128a4 + 0xd;
                }
                _DAT_800128a4 = uVar7;
                uVar7 = 0;
                if ((uVar2 & 1) != 0) {
                  uVar5 = _DAT_800128a0 >> 4;
                  uVar9 = _DAT_800128a4 - 4;
                  uVar7 = _DAT_800128a0 & 0xf;
                  _DAT_800128a0 = uVar5;
                  if ((int)uVar9 < 0x10) {
                    uVar1 = *_DAT_8001289c;
                    _DAT_8001289c = _DAT_8001289c + 1;
                    _DAT_800128a0 = uVar5 | (uint)uVar1 << (uVar9 & 0x1f);
                    uVar9 = _DAT_800128a4 + 0xc;
                  }
                  _DAT_800128a4 = uVar9;
                  uVar7 = uVar7 << 0xc;
                }
                if ((uVar2 & 2) != 0) {
                  uVar5 = _DAT_800128a0 >> 8;
                  uVar9 = _DAT_800128a4 - 8;
                  uVar8 = _DAT_800128a0 & 0xff;
                  _DAT_800128a0 = uVar5;
                  if ((int)uVar9 < 0x10) {
                    uVar1 = *_DAT_8001289c;
                    _DAT_8001289c = _DAT_8001289c + 1;
                    _DAT_800128a0 = uVar5 | (uint)uVar1 << (uVar9 & 0x1f);
                    uVar9 = _DAT_800128a4 + 8;
                  }
                  _DAT_800128a4 = uVar9;
                  uVar7 = uVar7 | uVar8 << 0x10;
                }
                uVar9 = _DAT_800128a0;
                if ((uVar2 & 4) != 0) {
                  _DAT_800128a0 = _DAT_800128a0 >> 8;
                  uVar2 = _DAT_800128a4 - 8;
                  if ((int)uVar2 < 0x10) {
                    uVar1 = *_DAT_8001289c;
                    _DAT_8001289c = _DAT_8001289c + 1;
                    _DAT_800128a0 = _DAT_800128a0 | (uint)uVar1 << (uVar2 & 0x1f);
                    uVar2 = _DAT_800128a4 + 8;
                  }
                  _DAT_800128a4 = uVar2;
                  uVar7 = uVar7 | uVar9 << 0x18;
                }
                puVar3 = puVar3 + unaff_s0;
                while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
                  *puVar3 = *puVar3 | uVar7;
                  puVar3 = puVar3 + 1;
                }
                puVar3 = puVar3 + -1;
                uVar2 = _DAT_800128a4;
              } while( true );
            }
            uVar7 = _DAT_800128a0 & 0xffff;
            uVar9 = _DAT_800128a4 - 0x10;
            _DAT_800128a0 = uVar6;
            if ((int)uVar9 < 0x10) {
              uVar1 = *_DAT_8001289c;
              _DAT_8001289c = _DAT_8001289c + 1;
              _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar9 & 0x1f);
              uVar9 = _DAT_800128a4;
            }
            _DAT_800128a4 = uVar9;
            uVar7 = uVar7 >> 5;
          }
          else {
            uVar7 = _DAT_800128a0 & 0xfff;
            uVar9 = _DAT_800128a4 - 0xc;
            _DAT_800128a0 = uVar6;
            if ((int)uVar9 < 0x10) {
              uVar1 = *_DAT_8001289c;
              _DAT_8001289c = _DAT_8001289c + 1;
              _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar9 & 0x1f);
              uVar9 = _DAT_800128a4 + 4;
            }
            _DAT_800128a4 = uVar9;
            uVar7 = uVar7 >> 4;
          }
        }
        else {
          uVar7 = _DAT_800128a4 - 3;
          _DAT_800128a0 = uVar6;
          if ((int)uVar7 < 0x10) {
            uVar1 = *_DAT_8001289c;
            _DAT_8001289c = _DAT_8001289c + 1;
            _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar7 & 0x1f);
            uVar7 = _DAT_800128a4 + 0xd;
          }
          _DAT_800128a4 = uVar7;
          uVar7 = 3;
        }
      }
      else {
        uVar7 = _DAT_800128a4 - 2;
        _DAT_800128a0 = uVar6;
        if ((int)uVar7 < 0x10) {
          uVar1 = *_DAT_8001289c;
          _DAT_8001289c = _DAT_8001289c + 1;
          _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar7 & 0x1f);
          uVar7 = _DAT_800128a4 + 0xe;
        }
        _DAT_800128a4 = uVar7;
        uVar7 = 2;
      }
    }
    else {
      uVar7 = _DAT_800128a4 - 1;
      _DAT_800128a0 = uVar6;
      if ((int)uVar7 < 0x10) {
        uVar1 = *_DAT_8001289c;
        _DAT_8001289c = _DAT_8001289c + 1;
        _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar7 & 0x1f);
        uVar7 = _DAT_800128a4 + 0xf;
      }
      _DAT_800128a4 = uVar7;
      uVar7 = 1;
    }
    uVar6 = _DAT_800128a0 >> 1;
    if ((_DAT_800128a0 & 1) == 0) {
      uVar6 = _DAT_800128a0 >> 2;
      if ((_DAT_800128a0 & 2) == 0) {
        uVar6 = _DAT_800128a0 >> 3;
        if ((_DAT_800128a0 & 4) == 0) {
          uVar6 = _DAT_800128a0 >> 8;
          if ((_DAT_800128a0 & 8) == 0) {
            uVar6 = _DAT_800128a0 >> 0xe;
            if ((_DAT_800128a0 & 0x10) == 0) {
              uVar6 = _DAT_800128a0 >> 6;
              if ((_DAT_800128a0 & 0x20) == 0) {
                _DAT_800128a0 = _DAT_800128a0 >> 7;
                uVar6 = _DAT_800128a4 - 7;
                if ((int)uVar6 < 0x10) {
                  uVar1 = *_DAT_8001289c;
                  _DAT_8001289c = _DAT_8001289c + 1;
                  _DAT_800128a0 = _DAT_800128a0 | (uint)uVar1 << (uVar6 & 0x1f);
                  uVar6 = _DAT_800128a4 + 9;
                }
                _DAT_800128a4 = uVar6;
                uVar5 = _DAT_800128a0 >> 0xc;
                uVar6 = _DAT_800128a4 - 0xc;
                uVar9 = _DAT_800128a0 & 0xfff;
                _DAT_800128a0 = uVar5;
                if ((int)uVar6 < 0x10) {
                  uVar1 = *_DAT_8001289c;
                  _DAT_8001289c = _DAT_8001289c + 1;
                  _DAT_800128a0 = uVar5 | (uint)uVar1 << (uVar6 & 0x1f);
                  uVar6 = _DAT_800128a4 + 4;
                }
                _DAT_800128a4 = uVar6;
                uVar9 = uVar9 | 0xfffff000;
              }
              else {
                uVar9 = _DAT_800128a4 - 6;
                _DAT_800128a0 = uVar6;
                if ((int)uVar9 < 0x10) {
                  uVar1 = *_DAT_8001289c;
                  _DAT_8001289c = _DAT_8001289c + 1;
                  _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar9 & 0x1f);
                  uVar9 = _DAT_800128a4 + 10;
                }
                _DAT_800128a4 = uVar9;
                uVar5 = _DAT_800128a0 >> 2;
                uVar6 = _DAT_800128a4 - 2;
                uVar9 = _DAT_800128a0 & 3;
                _DAT_800128a0 = uVar5;
                if ((int)uVar6 < 0x10) {
                  uVar1 = *_DAT_8001289c;
                  _DAT_8001289c = _DAT_8001289c + 1;
                  _DAT_800128a0 = uVar5 | (uint)uVar1 << (uVar6 & 0x1f);
                  uVar6 = _DAT_800128a4 + 0xe;
                }
                _DAT_800128a4 = uVar6;
                uVar9 = ~uVar9;
              }
            }
            else {
              uVar9 = _DAT_800128a0 & 0x3fff;
              uVar5 = _DAT_800128a4 - 0xe;
              _DAT_800128a0 = uVar6;
              if ((int)uVar5 < 0x10) {
                uVar1 = *_DAT_8001289c;
                _DAT_8001289c = _DAT_8001289c + 1;
                _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar5 & 0x1f);
                uVar5 = _DAT_800128a4 + 2;
              }
              _DAT_800128a4 = uVar5;
              uVar9 = uVar9 >> 5;
            }
          }
          else {
            uVar9 = _DAT_800128a0 & 0xff;
            uVar5 = _DAT_800128a4 - 8;
            _DAT_800128a0 = uVar6;
            if ((int)uVar5 < 0x10) {
              uVar1 = *_DAT_8001289c;
              _DAT_8001289c = _DAT_8001289c + 1;
              _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar5 & 0x1f);
              uVar5 = _DAT_800128a4 + 8;
            }
            _DAT_800128a4 = uVar5;
            uVar9 = uVar9 >> 4;
          }
        }
        else {
          uVar9 = _DAT_800128a4 - 3;
          _DAT_800128a0 = uVar6;
          if ((int)uVar9 < 0x10) {
            uVar1 = *_DAT_8001289c;
            _DAT_8001289c = _DAT_8001289c + 1;
            _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar9 & 0x1f);
            uVar9 = _DAT_800128a4 + 0xd;
          }
          _DAT_800128a4 = uVar9;
          uVar9 = 0;
        }
      }
      else {
        uVar9 = _DAT_800128a4 - 2;
        _DAT_800128a0 = uVar6;
        if ((int)uVar9 < 0x10) {
          uVar1 = *_DAT_8001289c;
          _DAT_8001289c = _DAT_8001289c + 1;
          _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar9 & 0x1f);
          uVar9 = _DAT_800128a4 + 0xe;
        }
        _DAT_800128a4 = uVar9;
        uVar9 = 1;
      }
    }
    else {
      uVar9 = _DAT_800128a4 - 1;
      _DAT_800128a0 = uVar6;
      if ((int)uVar9 < 0x10) {
        uVar1 = *_DAT_8001289c;
        _DAT_8001289c = _DAT_8001289c + 1;
        _DAT_800128a0 = uVar6 | (uint)uVar1 << (uVar9 & 0x1f);
        uVar9 = _DAT_800128a4 + 0xf;
      }
      _DAT_800128a4 = uVar9;
      uVar9 = 2;
    }
    uVar2 = uVar2 & 0xfffffffe;
    while (uVar7 = uVar7 - 1, uVar7 != 0xffffffff) {
      uVar2 = uVar2 + uVar9;
      *puVar4 = uVar2 >> 1;
      puVar4 = puVar4 + 1;
    }
  } while( true );
}
