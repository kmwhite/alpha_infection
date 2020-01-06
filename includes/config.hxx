#define AI_CONFIG_NAME alpha_infection.cfg

namespace ai {
    class Config {
        public:
            bool create(void);
            bool update(void);
            bool load(void);
            bool save(void);

        private:
            char *_home_dir(void);
    };
}
