/* FUN_80074860
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074860  body 0x80074860..0x80074bab  size 148 B
 * body sha256 f23b47d279c259f16ca1aec9e738770fab4b8ceccdbd0a15a0eecbe21f2005af
 * provider record sha256 42e8c9fb156cf6e742b718db706837478cfe7ce244c6802724775a116668602c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80074860(void)

{
  ushort *puVar1;
  
  switch(DAT_800e861d) {
  case '\0':
    break;
  case '\x01':
    if (DAT_800e8ef0 == '0') {
      DAT_8010b297 = DAT_800e8ef0;
    }
    else {
      _DAT_8013a12c = FUN_8008c51c(0x1f);
      DAT_8010b297 = '\x1f';
    }
    FUN_8004ac04(0,0x100,3,0xff000000);
    DAT_800e861d = '\x02';
    break;
  case '\x02':
    if ((DAT_8010b294 & 0x80) == 0) {
      if ((DAT_8010b294 & 1) == 0) {
        FUN_80083758(&DAT_800e8ec0,*(undefined2 *)(DAT_800dfbe0 + 0xc));
        FUN_80077adc(0x2270000,0);
        if (DAT_800e8ef0 == '0') {
          DAT_8010b297 = DAT_800e8ef0;
        }
        else {
          DAT_8010b297 = '\x1f';
          (&DAT_800e8ec9)[_DAT_8013a12c * 4] = (&DAT_800e8ec9)[_DAT_8013a12c * 4] + -1;
          if ((&DAT_800e8ec9)[_DAT_8013a12c * 4] == '\0') {
            (&DAT_800e8eca)[_DAT_8013a12c * 4] = 0;
            (&DAT_800e8ec8)[_DAT_8013a12c * 4] = 0;
          }
          FUN_8008c568();
        }
        FUN_8004ac04(0,0x100,5,0xff000000);
      }
      DAT_800e8924 = 0;
      DAT_800e861d = '\0';
    }
    break;
  default:
    goto LAB_80074b88;
  case '\x04':
    if ((DAT_800e110c & 0x8000) == 0) {
      FUN_80083c14((int)DAT_800e8cb0);
      DAT_800e110c = DAT_800e110c & 0xfffffeff;
      (&DAT_800e18f8)[(uint)*(byte *)(_DAT_8013a130 + 6) * 0xda] =
           (&DAT_800e18f8)[(uint)*(byte *)(_DAT_8013a130 + 6) * 0xda] & 0xffffffee;
      DAT_800e8924 = 0;
      DAT_800e861d = '\0';
    }
    break;
  case '\x05':
    _DAT_8013a134 = DAT_800dfbe0;
    puVar1 = (ushort *)(DAT_800dfbe0 + 0xe);
    DAT_800dfbe0 = (&DAT_800dfb60)[*(ushort *)(DAT_800dfbe0 + 0xe)];
    _DAT_8013a130 = (&DAT_800dfb60)[*puVar1] + 0xc;
    DAT_8012bfa8 = 2;
    DAT_80131780 = 1;
    DAT_800e110c = DAT_800e110c & 0xffffffbf | 0x8100;
    DAT_800e8605 = *(char *)((&DAT_800dfb60)[*puVar1] + 0xd);
    DAT_8010b297 = DAT_800e8605;
LAB_80074b88:
    DAT_800e861d = DAT_800e861d + -1;
  }
  return;
}
