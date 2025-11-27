App:
  nam: 'fun_game'
  prj: 'MyProject'

  default:
    PlatformSetting:
      bax:
        GameBaseAxis:
          axs: 'x'
          siz: 1000
      ful: true
      rsl:
        # 16:10
        - [1280,  800, 'x', 900]
        - [1440,  900, 'x', 900]
        - [1680, 1050, 'x', 900]

        # 16:9
        - [1280,  720]
        - [1366,  768]
        - [1600,  900]
        - [1920, 1080]

  windows:
    PlatformSetting:
      bax:
        GameBaseAxis:
          axs: 'x'
          siz: 1000
      ful: false
      ttl: false
      rsl:
        # 16:10
        - [1280,  800, 'x', 900]
        - [1440,  900, 'x', 900]
        - [1680, 1050, 'x', 900]

        # 16:9
        - [1280,  720]
        - [1366,  768]
        - [1600,  900]
        - [1920, 1080]

  steamdeck:
    PlatformSetting:
      bax:
        GameBaseAxis:
          axs: 'x'
          siz: 1000
      wid: 1280
      hei: 800
      ful: true
      rsl:
        # 16:10
        - [1280,  800, 'x', 900]
        - [1440,  900, 'x', 900]
        - [1680, 1050, 'x', 900]

        # 16:9
        - [1280,  720]
        - [1366,  768]
        - [1600,  900]
        - [1920, 1080]

  android:
    PlatformSetting:
      bax:
        GameBaseAxis:
          axs: 'x'
          siz: 1000
      wid: 1080
      hei: 1920
      ful: true
      rsl:
        - [1080, 1920]

  web:
    PlatformSetting:
      bax:
        GameBaseAxis:
          axs: 'x'
          siz: 1000
      wid: 1280
      hei: 720
      ful: false
      rsl:
        # 16:9
        - [1280,  720]

  editor:
    PlatformSetting:
      bax:
        GameBaseAxis:
          axs: 'x'
          siz: 1000
      wid:
        '$window_width': 1280
      hei:
        '$window_height': 720
      ful: false
      rsl:
        # 16:10
        - [ 640,  400, 'x', 900]
        - [1280,  800, 'x', 900]
        - [1440,  900, 'x', 900]
        - [1680, 1050, 'x', 900]

        # 16:9
        - [ 640,  360]
        - [ 960,  540]
        - [1280,  720]
        - [1366,  768]
        - [1600,  900]
        - [1920, 1080]
